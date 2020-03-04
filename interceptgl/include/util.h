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
#include<sys/syscall.h>
#include <execinfo.h>
/* 
 * We use libpfm and helper functions from Stephane Eranian 
 */
#include "perf_util.h"
#include "pfm_operations.h"
#include "pfm_common.h"

#define NUM_COUNTERS 6
#define MY_LOG(fmt, ...)				\
	do { fprintf(stderr, "%s: "fmt , __func__,	\
		     ## __VA_ARGS__);} while (0);

typedef struct __thread_pfm_context{
        perf_event_desc_t *fds;
        int num_fds;
        pid_t tid;
        int grouped;
        int enabled;
}thread_pfm_context_t;

struct args {
    void* myfunc;
    void* arg;
    int   thr_idx;
};

long long gettime_nanoTime(void);
void MY_TRACE(void);

void perf_start();
void perf_end();
