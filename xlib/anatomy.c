#include<X11/Xlib.h> 	// Every Xlib program must include this
#include<assert.h>   	// test return value in a lazy way
#include<unistd.h> 	// So we got the profile for 10 seconds

#define NIL (0)		// A name for the void pointer


int main(){
	Display *dpy = XOpenDisplay(NIL);
	assert(dpy);
	
	int blackColor 	= BlackPixel(dpy, DefaultScreen(dpy));
	int whiteColor 	= WhitePixel(dpy, DefaultScreen(dpy));
	Window w 	= XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),0,0,
			  200, 100, 0, blackColor, blackColor);
	// we want to get MapNotify events: our app is intrested in following events
	XSelectInput(dpy, w, StructureNotifyMask);
	// Map the window(make it appear on the screen)
	XMapWindow(dpy, w);
	// Create a "Graphic Contex"
	GC gc = XCreateGC(dpy, w, 0, NIL);
	// Tell the GC we draw using the white color
	XSetForeground(dpy, gc, whiteColor);
	//wait for the MapNotify event
	for(;;){
		XEvent e;
		XNextEvent(dpy, &e);
		if(e.type == MapNotify)
			break;
	}
	// draw the line
	XDrawLine(dpy, w, gc, 10, 60, 180, 20);
	// Send the "DrawLine" request to the server
	XFlush(dpy);
	sleep(10);
	return 0;
}
