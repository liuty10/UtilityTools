#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#include <execinfo.h>
#define MY_LOG(fmt, ...)				\
	do { fprintf(stderr, "%s: "fmt , __func__,	\
		     ## __VA_ARGS__);} while (0);

long long gettime_nanoTime(void);
void MY_TRACE(void);

void perf_start();
void perf_end();
