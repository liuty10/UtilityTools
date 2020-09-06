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
using namespace std;

typedef XID GLXDrawable;
typedef void (*PFNGLXSWAPBUFFERSPROC)(Display *dpy, GLXDrawable drawable);
typedef void* (*PFNDLSYMPROC)(void*, const char*);
typedef void* (*PFNGLXGETPROCADDRESSPROC)(const GLubyte*);

static PFNDLSYMPROC o_dlsym = 0;
static PFNGLXGETPROCADDRESSPROC _glXGetProcAddress = 0;

long long gettime_nanoTime(void)
{
    struct timespec __tv;
    clock_gettime(CLOCK_MONOTONIC,&__tv);
    return(long long)(__tv.tv_sec * 1e9 + __tv.tv_nsec);
}
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

    if(time_tmp1!=0){
        fprintf(stderr, "App time: %f, oneFrameTime: %f\n",
                           (time_tmp0-time_tmp1)/1000000.0,
                           (time_tmp0-last_time_tmp0)/1000000.0);
    }
    if(!_glXSwapBuffers){
        _glXSwapBuffers = (PFNGLXSWAPBUFFERSPROC)o_dlsym(RTLD_NEXT, "glXSwapBuffers");
    }

    last_time_tmp0 = time_tmp0;
    _glXSwapBuffers(dpy, drawable);
    time_tmp1 = gettime_nanoTime();
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

#ifdef __cplusplus
}
#endif
