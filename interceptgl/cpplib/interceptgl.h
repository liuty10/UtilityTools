#ifndef INTERCEPT_H
#define INTERCEPT_H

#include <X11/Xlib.h>
#include <GL/gl.h>

extern "C"{
	void glXSwapBuffer(Display *dpy, GLXDrawable drawable);
        int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *realthread, void *arg);
}

#endif //INTERCEPT_H
