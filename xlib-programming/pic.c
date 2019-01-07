#include<X11/Xlib.h> 	// Every Xlib program must include this
#include<X11/Xutil.h>
#include<assert.h>   	// test return value in a lazy way
#include<unistd.h> 	// So we got the profile for 10 seconds
#include<stdio.h> 	// So we got the profile for 10 seconds

#define NIL (0)		// A name for the void pointer
#define bool int
#define true 1
#define false 0

void draw(char *rgb_out, int w, int h)
{
        int i = 0;

        for (i = 0;i < w*h*4;i += 4) {
                rgb_out[i + 0] = 100;
                rgb_out[i + 1] = 100;
                rgb_out[i + 2] = 200;
                rgb_out[i + 3] = 30;
        }

        return;
}

XImage *create_ximage(Display *display, Visual *visual, int width, int height)
{
        char *image32 = (char *)malloc(width * height * 4);
        draw(image32, width, height);
        return XCreateImage(display, visual, 24,
                            ZPixmap, 0, image32,
                            width, height, 32, 0);
}


int main(){
        int win_b_color;
        int win_w_color;
        XEvent xev;
        Window window;
        GC gc;
        Display *display = XOpenDisplay(NULL);
        Visual *visual;
        XImage *ximage;

        win_b_color = BlackPixel(display, DefaultScreen(display));
        win_w_color = BlackPixel(display, DefaultScreen(display));
        window = XCreateSimpleWindow(display,
                                DefaultRootWindow(display),
                                0, 0, 600, 400, 0,
                                win_b_color, win_w_color);

        visual = DefaultVisual(display, 0);

        XSelectInput(display, window, ExposureMask | KeyPressMask);

        XMapWindow(display, window);
        XFlush(display);
        gc = XCreateGC(display, window, 0, NULL);
        ximage = create_ximage(display, visual, 200, 200);
        XEvent event;
        bool exit = false;

        while (!exit) {
                int r;

                XNextEvent(display, &event);

                if (event.type == Expose)
                {
                    r = XPutImage(display, window,
                            gc, ximage, 0, 0, 0, 0,
                            200, 200);
                    printf("RES: %i\n", r);
                }
                else if (event.type == KeyPress)
                    exit = true;
		else{
			;
		}
        }
	return 0;
}
