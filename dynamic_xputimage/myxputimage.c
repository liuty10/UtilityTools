#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <X11/Xlib.h>
#include <X11/X.h>
#include <dlfcn.h>

int XPutImage(Display *display, Drawable d, GC gc, XImage *image, int src_x, int src_y, int dest_x, int dest_y, unsigned int width, unsigned int height)
{
    //static int (*real_XPutImage)(Display*, Drawable, GC, XImage*, int, int, int, int, unsigned int, unsigned int) = NULL; 

    //if (!real_XPutImage)
    //    real_XPutImage = dlsym(RTLD_NEXT, "XPutImage");

    //int result = real_XPutImage(display,d,gc,image,src_x,src_y,dest_x,dest_y,width,height); 

    fprintf(stderr, "intercepting XPutImage done.\n");
    return 0;
}
