#define _GNU_SOURCE
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>
#include "util.h"

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
    // instructions
    // cycles
    // LLC_MISSES
    // LLC_REFERENCES
    perf_start("instructions,cycles,LLC_MISSES,LLC_REFERENCES");
}
