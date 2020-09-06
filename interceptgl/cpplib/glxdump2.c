/*
  Copyright (C) 2005 Nick Lowe (nickl@vislab.usyd.edu.au)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.

  ABOUT
  ------

  This "library" can be used with some GLX programs to record frames
  to disk. It makes a couple of assumptions:

  - The program only uses one GL context

  - The program uses double-buffering and calls glXSwapBuffers()
  only at the end of each frame

  - The window does not get resized during program executation

  It outputs .jpg files to the current working directory. This can be
  easily changed by modifying the code (not elegant I know).

  Even with these assumptions, this "library" should cover a lot of
  GLX and GLUT programs. I've tested Tux Racer, many GL screensavers,
  and a few of my own programs (that use GLUT).


  DEPENDENCIES
  ------------

  Aside from common dependencies, this file requires OpenIL
  (aka. DevIL) to save images (install "libdevil-dev" under Ubuntu).


  USAGE
  -----

  Compile using:

    gcc -Wall -O2 -fpic -shared -ldl -lIL -o libglxdump.so glxdump.c
 
  or for DEBUG (more output):

    gcc -Wall -O2 -fpic -shared -ldl -lIL -DDEBUG -o libglxdump.so glxdump.c

  Run using:

    LD_PRELOAD=`pwd`/libglxdump.so [some glx application]

  Encode using:

    mogrify -resize [width]x[height]! *.jpg
    ffmpeg -s [width]x[height] -i image_%10d.jpg video.avi
   
  (NOTES: mogrify is *very* slow; ffmpeg has many options for better quality)


  REFERENCES
  ----------

  http://www.linuxjournal.com/article/7795
  http://www.amparo.net/ce155/fork-ex.html
  http://www.opengroup.org/onlinepubs/009695399/functions/exec.html
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>
#include <math.h>

#include <dlfcn.h>

#include <GL/glx.h>
#include <IL/il.h>


#define VIDEO_TIME_STEP 40.0 /* milliseconds between frames (40.0 = 25 fps) */


/* library interception variables */
static void* lib_handle = 0;
static void (*lib_glXSwapBuffers)(Display *dpy, GLXDrawable drawable) = 0;

/* timing variables */
static double video_time;

/* image saving variables */
static GLint viewport[4];
static ILuint image_id = 0;
static GLubyte* image_data = 0;
static int image_number = 0;


/*
 * Output error code and exit
 */
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


/*
 * Load GLX library and find glXSwapBuffers() function
 */
inline static void load_library(void)
{
    /* open library (NOTE: you may need to change this filename!) */
    lib_handle = dlopen("/usr/lib/libGL.so", RTLD_LAZY);
    /*lib_handle = dlopen("/usr/lib/fglrx/libGL.so.1", RTLD_LAZY);*/
    
    if (!lib_handle)
	handle_dlerror();
    
    /* intercept library glxSwapBuffers function */
    lib_glXSwapBuffers = dlsym(lib_handle, "glXSwapBuffers");    
    handle_dlerror();
}


/*
 * Create an image to store each frame in (using OpenIL)
 */
inline static void create_image(void)
{
    int width;
    int height;
    
    glGetIntegerv(GL_VIEWPORT, viewport);
    
    width = viewport[2] - viewport[0];
    height = viewport[3] - viewport[1];

    printf("Capturing at %dx%d\n", width, height);

    ilInit();
    
    ilGenImages(1, &image_id);
    ilBindImage(image_id);
    
    image_data = (GLubyte*)malloc(width * height * 4 * sizeof(GLubyte));
    ilTexImage(width, height, 1, 4, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    
#ifdef DEBUG
    printf("Created image using viewport (%d, %d, %d, %d)\n",
	   viewport[0], viewport[1], viewport[2], viewport[3]);
#endif

}


/*
 * Read-back a frame from the GL framebuffer
 */
inline static void capture_frame(void)
{
    glReadPixels(viewport[0], viewport[1], viewport[2], viewport[3],
		 GL_RGBA, GL_UNSIGNED_BYTE, image_data);

#ifdef DEBUG
    printf("Captured frame\n");
#endif
}

static char filename[32];

inline static void set_filename(void)
{
    sprintf(filename, "image_%.10u.jpg" , image_number);
}

/*
 * Dump the current frame to disk
 */
inline static void dump_frame(void)
{
    /* save image (NOTE: you can change to a different file format!) */
    ilSetData(image_data);
    ilSave(IL_JPG, filename);

#ifdef DEBUG
    printf("Dumped frame to %s\n", filename);
#endif
}


/*
 * Record time that capturing starts
 */
inline static void start_timer(void)
{
    struct timeval tp;

    gettimeofday(&tp, 0);

    video_time = 1000.0 * tp.tv_sec + 0.001 * tp.tv_usec;
}


/*
 * Dump frames at the correct rate (NOTE: will write duplicates or drop frames!)
 */
inline static void dump_frames()
{
    struct timeval tp;
    double t;
	
    gettimeofday(&tp, 0);
	
    t = 1000.0 * tp.tv_sec + 0.001 * tp.tv_usec;

    /* only capture if we will be dumping any frames */
    if ((t - video_time) > VIDEO_TIME_STEP)
    {
	capture_frame();

	set_filename();
	dump_frame();

	image_number++;

	video_time += VIDEO_TIME_STEP;
    }

    while ((t - video_time) > VIDEO_TIME_STEP)
    {
	static char old_filename[32];

	int pid;

	/* record current frame filename */
	strcpy(old_filename, filename);

	/* fork a child process to copy frames (to fill in timestep) */
	if ((pid = fork()) < 0)
	{
	    perror("Problem calling vfork");
	    exit(1);
	}

	/* child copies frames and exits */
	if (pid == 0)
	{
	    set_filename();

	    if (execlp("cp", "cp", old_filename, filename, (char*)0) == -1)
	    {
		perror("Error copying frame");
		exit(1);
	    }
	    
#ifdef DEBUG
	    printf("Copied frame from %s to %s\n", old_filename, filename);
#endif
	    exit(0);
	}       

	wait();

	image_number++;
	
	video_time += VIDEO_TIME_STEP;
    }
}


/*
 * Our glXSwapBuffers function that intercepts the "real" function.
 *
 * Load library if necessary. Then dump a frame and call the "real"
 * glXSwapBuffers function.
 */
void glXSwapBuffers(Display *dpy, GLXDrawable drawable)
{    
    if (!lib_handle)
    {
	load_library();
	create_image();
	start_timer();
    }

    dump_frames();

    lib_glXSwapBuffers(dpy, drawable);

#ifdef DEBUG
    printf("Intercepted call to glXSwapBuffers()\n");
#endif
}
