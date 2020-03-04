#define _GNU_SOURCE
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>
#include "util.h"

//#include <pthread.h>

extern int 	thr_ctx_idx;
extern int 	pfm_init_flag;
extern thread_pfm_context_t thread_ctxs[MAX_NUM_THREADS];

void glXSwapBuffers(Display *dpy, GLXDrawable drawable){
    static void(*real_swapbuffer)(Display *, GLXDrawable) = NULL;
    static long long last_time_tmp0=0;
    static long long time_tmp0=0;
    static long long time_tmp1=0;
    perf_end();
    if(!real_swapbuffer)
        real_swapbuffer = dlsym(RTLD_NEXT, "glXSwapBuffers");

    time_tmp0 = gettime_nanoTime();
    if(time_tmp1!=0)
        fprintf(stderr, "App time: %f, oneFrameTime: %f\n",(time_tmp0-time_tmp1)/1000000.0,(time_tmp0-last_time_tmp0)/1000000.0);
    last_time_tmp0 = time_tmp0;
    real_swapbuffer(dpy, drawable);
    time_tmp1 = gettime_nanoTime();
    perf_start();
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
    if(evns == NULL) evns="instructions,cycles"; 
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

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *realthread, void *arg){
    static int (*real_pthread_create)(pthread_t *, const pthread_attr_t *, void *, void *) = NULL;
    if(!real_pthread_create)
        real_pthread_create = dlsym(RTLD_NEXT, "pthread_create");

    struct args *myargs = (struct args *)malloc(sizeof(struct args));
    myargs->myfunc = realthread;
    myargs->arg    = arg;
    __atomic_fetch_add(&thr_ctx_idx, 1, __ATOMIC_SEQ_CST);
    myargs->thr_idx = thr_ctx_idx;
    return real_pthread_create(thread, attr, mythread, myargs);
}
