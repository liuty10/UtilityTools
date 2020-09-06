#define _GNU_SOURCE
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/syscall.h>
#include <time.h>
#include <string.h>

#include "util.h"
extern int 	glx_pid;
extern FILE* 	glxLogFp;
extern int 	thr_ctx_idx;
extern int 	pfm_init_flag;
extern thread_pfm_context_t thread_ctxs[MAX_NUM_THREADS];

typedef XID GLXDrawable;
typedef void (*PFNGLXSWAPBUFFERSPROC)(Display *dpy, GLXDrawable drawable);
typedef void* (*PFNDLSYMPROC)(void*, const char*);
typedef void* (*PFNGLXGETPROCADDRESSPROC)(const GLubyte*);

static PFNDLSYMPROC o_dlsym = 0;
static PFNGLXGETPROCADDRESSPROC _glXGetProcAddress = 0;

inline static void handle_dlerror(void)
{
    char* error;

    error = dlerror();
    
    if (error)
    {
	fprintf(stderr, "%s\n", error);
	exit(1);
    }  
}

void* mythread(void* input){
    void(*realthread)(void *) = NULL;
    realthread 	= ((struct args*)input)->myfunc;
    void* arg 	= ((struct args*)input)->arg;
    int thr_idx = ((struct args*)input)->thr_idx;
    if(pfm_init_flag != 0){
    	pfm_init_flag = pfm_operations_init();
    	if(pfm_init_flag != 0 ) errx(1, "PMU initialization failed\n");
    }
    thread_ctxs[thr_idx].tid = syscall( __NR_gettid );
    thread_ctxs[thr_idx].fds = NULL;
    thread_ctxs[thr_idx].num_fds = 0;
    char *evns = getenv("PFM_EVENTS");
    if(evns == NULL) evns="instructions,cycles,LLC_MISSES,LLC_REFERENCES"; 
    int ret = perf_setup_list_events(evns, &(thread_ctxs[thr_idx].fds),
                                       &(thread_ctxs[thr_idx].num_fds));
    if(ret || !(thread_ctxs[thr_idx].num_fds))
    	return NULL;

    for(int j = 0; j < thread_ctxs[thr_idx].num_fds; j++){
       thread_ctxs[thr_idx].fds[j].hw.disabled = 1;
       thread_ctxs[thr_idx].fds[j].hw.exclude_user = 0;
       thread_ctxs[thr_idx].fds[j].hw.exclude_kernel = 0;
       thread_ctxs[thr_idx].fds[j].hw.exclude_hv = 1;
       thread_ctxs[thr_idx].fds[j].hw.inherit = 0; /* only monitor the current thread */
       thread_ctxs[thr_idx].fds[j].fd = perf_event_open(&(thread_ctxs[thr_idx].fds[j].hw), 0, -1, -1, 0);
       if (thread_ctxs[thr_idx].fds[j].fd == -1) {
               warn("cannot attach event%d %s to thread [%d]: ", j,
                    thread_ctxs[thr_idx].fds[j].name, thread_ctxs[thr_idx].tid);
               return NULL;
       }
       DPRINTF("PMU context opened for thread [%d]\n", thread_ctxs[thr_idx].tid);
    }
    //call real thread;    
    realthread(arg);
}

#ifdef __cplusplus
extern "C"
{
#endif

void glXSwapBuffers(Display *dpy, GLXDrawable drawable){
    static PFNGLXSWAPBUFFERSPROC _glXSwapBuffers = 0;
    static long long last_time_tmp0=0;
    static long long time_tmp0=0;
    static long long time_tmp1=0;
    time_tmp0 = gettime_nanoTime();
    perf_end();

    if(glx_pid == 0){
        glx_pid = getpid();
    	glxLogFp = getLogFilePointer(glx_pid);
    }

    if(time_tmp1!=0){
        fprintf(glxLogFp, "App time: %f, oneFrameTime: %f\n",
                           (time_tmp0-time_tmp1)/1000000.0,
                           (time_tmp0-last_time_tmp0)/1000000.0);
    }
    if(!_glXSwapBuffers){
        _glXSwapBuffers = (PFNGLXSWAPBUFFERSPROC)o_dlsym(RTLD_NEXT, "glXSwapBuffers");
    }

    last_time_tmp0 = time_tmp0;
    _glXSwapBuffers(dpy, drawable);
    time_tmp1 = gettime_nanoTime();
    perf_start();
}

void *glXGetProcAddress(const GLubyte * str)
{
    if(_glXGetProcAddress==0)
        _glXGetProcAddress = (PFNGLXGETPROCADDRESSPROC)o_dlsym(RTLD_NEXT, "glXGetProcAddress");
    if(strcmp((const char*)str, "glXSwapBuffers")==0)return (void*)glXSwapBuffers;
    return _glXGetProcAddress(str);
}

void *glXGetProcAddressARB(const GLubyte *str)
{
    return glXGetProcAddress(str);
}

void *dlsym(void *handle, const char *name)
{
    fprintf(stderr, "Ha Ha...dlsym() Hooked:%s\n", name);
    if(strcmp(name, "glXGetProcAddressARB") == 0)
        return (void*)glXGetProcAddressARB;

    if(strcmp(name, "glXGetProcAddress") == 0)
        return (void*)glXGetProcAddress;

    if(strcmp(name, "glXSwapBuffers")==0)
        return (void*)glXSwapBuffers;

    if(!o_dlsym)
    {
        o_dlsym = (void*(*)(void *handle, const char *name)) dlvsym(RTLD_NEXT,"dlsym", "GLIBC_2.0");

        if(!o_dlsym)
            o_dlsym = (void*(*)(void *handle, const char *name)) dlvsym(RTLD_NEXT,"dlsym", "GLIBC_2.10");

        if(!o_dlsym)
            o_dlsym = (void*(*)(void *handle, const char *name)) dlvsym(RTLD_NEXT,"dlsym", "GLIBC_2.2.5");

        if(!o_dlsym)
            fprintf(stderr, "FAILED TO FIND DLSYM()\n");
        else
            fprintf(stderr, "found dlsym\n");
    }
    return (*o_dlsym)(handle, name);
}

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *realthread, void *arg){
    static int (*real_pthread_create)(pthread_t *, const pthread_attr_t *, void *, void *) = NULL;
    if(!real_pthread_create)
        real_pthread_create = dlsym(RTLD_NEXT, "pthread_create");

    struct args *myargs = (struct args *)malloc(sizeof(struct args));
    myargs->myfunc = realthread;
    myargs->arg    = arg;
    __atomic_fetch_add(&thr_ctx_idx, 1, __ATOMIC_SEQ_CST);
    myargs->thr_idx = thr_ctx_idx;
    /*if(glx_pid == 0){
        fprintf(stderr,"in pthread_create.\n");
        glx_pid = getpid();
        glxLogFp = getLogFilePointer(glx_pid);
    }
    fprintf(glxLogFp, "pthread_create intercepted.\n");*/
    return real_pthread_create(thread, attr, mythread, myargs);
}

#ifdef __cplusplus
}
#endif
