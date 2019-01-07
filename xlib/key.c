/* include the X library headers */
#include<X11/Xlib.h> 	// Every Xlib program must include this
#include<X11/Xutil.h>
#include<X11/Xos.h>

#include<stdio.h>
#include<stdlib.h>

#include<assert.h>   	// test return value in a lazy way
#include<unistd.h> 	// So we got the profile for 10 seconds

#define NIL (0)		// A name for the void pointer

/* Here are our X variables */
Display *dis;
int screen;
Window win;
GC gc;

/* Here are our X routines declared */
void int_x();
void close_x();
void redraw();


int main(){
	XEvent e;
	KeySym key;
	char text[255];
	init_x();

	for(;;){
		XNextEvent(dis, &e);
		if(e.type == Expose && e.xexpose.count==0){
			redraw();
			printf("You redraw the window\n");
		}
		if(e.type == KeyPress && XLookupString(&e.xkey,text,255,&key,0)==1){
			printf("You pressed the %c key!\n", text[0]);
			if(text[0]=='q'){
				close_x();
			}
		}
		if(e.type == ButtonPress){
			int x = e.xbutton.x, y = e.xbutton.y;
			strcpy(text, "X is FUN!");
			XSetForeground(dis,gc,rand()%e.xbutton.x%255);
			XDrawString(dis,win,gc,x,y,text,strlen(text));
			printf("You pressed a button at (%i, %i)\n",e.xbutton.x, e.xbutton.y);
		}
	}
	// draw the line
	return 0;
}

void init_x(){
	unsigned long black, white;
	dis = XOpenDisplay((char *)0);
	screen=DefaultScreen(dis);
	black=BlackPixel(dis,screen);
	white=WhitePixel(dis,screen);
        win = XCreateSimpleWindow(dis, DefaultRootWindow(dis),0,0,300,300,5,black, white);
 	printf("after creating\n");
	sleep(5);
	XSetStandardProperties(dis,win,"Howdy","Hi",None,NULL,0,NULL);
	XSelectInput(dis,win,ExposureMask|ButtonPressMask|KeyPressMask);
	gc = XCreateGC(dis,win,0,0);
	XSetBackground(dis,gc,white);
	XSetForeground(dis,gc,black);
	XClearWindow(dis, win);
	XMapRaised(dis, win);
 	printf("after XMapng\n");
	sleep(5);
}

void close_x(){
	XFreeGC(dis, gc);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);
	exit(1);
}

void redraw(){
	XClearWindow(dis,win);
}
