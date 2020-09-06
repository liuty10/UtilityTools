#include <X11/Xlib.h>
#include <GL/glx.h>
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>

//#include "util.h"
#include "interceptgl.h"
#include <string.h>
/*
extern int 	glx_pid;
extern FILE* 	glxLogFp;
extern int 	thr_ctx_idx;
extern int 	pfm_init_flag;
extern thread_pfm_context_t thread_ctxs[MAX_NUM_THREADS];
*/
/*
 * Output error code and exit
 */
/*inline static void handle_dlerror(void)
{
    char* error;

    error = dlerror();
    
    if (error)
    {
	fprintf(stderr, "%s\n", error);
	exit(1);
    }  
}
*/
#ifdef __cplusplus
extern "C"
{
#endif

//extern void *__libc_dlsym (void *, const char *);
/*
void glXSwapBuffers(Display *dpy, GLXDrawable drawable){
    static void(*real_swapbuffer)(Display *, GLXDrawable) = NULL;
    static long long last_time_tmp0=0;
    static long long time_tmp0=0;
    static long long time_tmp1=0;
    time_tmp0 = gettime_nanoTime();

    if(glx_pid == 0){
        glx_pid = getpid();
    	glxLogFp = getLogFilePointer(glx_pid);
    }

    if(time_tmp1!=0){
        fprintf(glxLogFp, "App time: %f, oneFrameTime: %f\n",
                           (time_tmp0-time_tmp1)/1000000.0,
                           (time_tmp0-last_time_tmp0)/1000000.0);
    }
    perf_end();
    if(!real_swapbuffer){
        //real_swapbuffer = (void(*)(Display *, GLXDrawable))dlsym(RTLD_NEXT, "glXSwapBuffers");
        void * lib_handle = dlopen("/usr/lib/libGL.so.1", RTLD_LAZY);
        if (!lib_handle)
            handle_dlerror();
   //real_swapbuffer = (void(*)(Display *, GLXDrawable))dlsym(lib_handle, "glXSwapBuffers");
   real_swapbuffer = (void(*)(Display *, GLXDrawable))__libc_dlsym(lib_handle, "glXSwapBuffers");
    }

    last_time_tmp0 = time_tmp0;
    real_swapbuffer(dpy, drawable);
    time_tmp1 = gettime_nanoTime();
    perf_start();
}

void* mythread(void* input){
    void(*realthread)(void *) = NULL;
    realthread 	= (void(*)(void *))((struct args*)input)->myfunc;
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
       thread_ctxs[thr_idx].fds[j].hw.inherit = 0;
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

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *realthread, void *arg){
    static int (*real_pthread_create)(pthread_t *, const pthread_attr_t *, void *, void *) = NULL;
    if(!real_pthread_create)
        real_pthread_create = (int (*)(pthread_t *, const pthread_attr_t *, void *, void *))dlsym(RTLD_NEXT, "pthread_create");

    struct args *myargs = (struct args *)malloc(sizeof(struct args));
    myargs->myfunc = realthread;
    myargs->arg    = arg;
    __atomic_fetch_add(&thr_ctx_idx, 1, __ATOMIC_SEQ_CST);
    myargs->thr_idx = thr_ctx_idx;
    if(glx_pid == 0){
        fprintf(stderr,"in pthread_create.\n");
        glx_pid = getpid();
        glxLogFp = getLogFilePointer(glx_pid);
    }
    fprintf(glxLogFp, "pthread_create intercepted.\n");
    return real_pthread_create(thread, attr, (void*)mythread, myargs);
}*/

/*void *dlsym(void *handle, const char *symbol)
{
    fprintf(stderr, "Ha Ha...dlsym() Hooked\n");
    void* result = __libc_dlsym(handle, symbol);
    return result;
}*/

extern void *_dl_sym(void *, const char *, void *);
extern void *dlsym(void *handle, const char *name)
{
    fprintf(stderr, "Ha Ha...dlsym() Hooked:%s\n", name);
    static void * (*real_dlsym)(void *, const char *)=NULL;
    if (real_dlsym == NULL)
        real_dlsym=(void* (*)(void*, const char*))_dl_sym(RTLD_NEXT, "dlsym", (void*)dlsym);
    /* my target binary is even asking for dlsym() via dlsym()... */
    if (!strcmp(name,"dlsym")) 
        return (void*)dlsym;
    return real_dlsym(handle,name);
}

#ifdef __cplusplus
}
#endif

