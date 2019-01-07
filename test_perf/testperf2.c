#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <linux/hw_breakpoint.h>
#include <asm/unistd.h>
#include <sys/mman.h>

#include <stdint.h>
#ifdef _MSC_VER
#include <intrin.h> /*  for rdtscp and clflush */
#pragma optimize("gt",on)
#else
#include <x86intrin.h> /*  for rdtscp and clflush */
#endif

#define CEILING_POS(X) ((X-(int)(X)) > 0 ? (int)(X+1) : (int)(X))

#define PAGE_SIZE 4096
#define CACHE_LINE_SIZE 64
#define NUM_CACHE_LINES_PER_PAGE (PAGE_SIZE / CACHE_LINE_SIZE)
#define NUM_LINES_PER_PAGE (PAGE_SIZE / CACHE_LINE_SIZE)
#define NUM_LINES 100000
#define NUM_CYCLES 10

typedef enum { false = 0, true } bool;

static inline long perf_event_open(struct perf_event_attr *hw_event, pid_t pid, int cpu, int group_fd, unsigned long flags) {
		return syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
}

static inline const char * bool_to_str(bool value) {
		return value ? "true" : "false";
}

int main(int argc, char **argv) {
		bool exclude_kernel = true;
		bool exclude_user = false;
		bool no_touch = false;
		bool no_flush = false;
		bool exit_flush = false;
		bool do_madvise = false;
		bool debug_mode = false;
		int fd;
		register int i;
		int j;
		int numCycles = NUM_CYCLES;
		int numLines = NUM_LINES;
		int numTouch = 1;
		int sleep_us = 0;
		int pg_stride = 1;
		int ca_stride = 1;
		struct perf_event_attr pe;
		uint64_t count;

		for(i = 1; i < argc; i++) {
				if((strcmp(argv[i], "--help") == 0) ||
					 (strcmp(argv[i], "--?") == 0) ||
					 (strcmp(argv[i], "-?") == 0)) {
							printf("Options:\n");
							printf("    --help, -?            print this message\n");
							printf("    --kern, -k            include kernel mode in count\n");
							printf("    --nouser, -U          exclude user mode in count\n");
							printf("    --lines, -l <num>     number of cache lines to use\n");
							printf("    --notouch             do not write to any cache lines\n");
							printf("    --noflush             do not perform cache flush between loops\n");
							printf("    --exitflush           perform a cache flush on program exit\n");
							printf("    --madvise             perform an madvise between loops\n");
							printf("    --usec, -s <num>      sleep for num microseconds between runs\n");
							printf("    --ncyc, -c <num>      number of experiment cycles (default = 2)\n");
							printf("    --pstride, -ps <num>  stride amount for looping over memory pages (default = 1)\n");
							printf("    --cstride, -cs <num>  stride amount for looping over cache lines (default = 1)\n");
							printf("    --touch, -t <num>     number of cache lines to touch per page (default = 1)\n");
							printf("    --debug, -d           debug mode\n\n");
							return EXIT_FAILURE;
				}
				if((strcmp(argv[i], "--lines") == 0) ||
					 (strcmp(argv[i], "-l") == 0)) {
						numLines = atoi(argv[i + 1]);
						i++;
						continue;
				}
				if((strcmp(argv[i], "--kern") == 0) ||
					 (strcmp(argv[i], "-k") == 0)) {
						exclude_kernel = false;
				}
				if((strcmp(argv[i], "--nouser") == 0) ||
					 (strcmp(argv[i], "-U") == 0)) {
						exclude_user = true;
				}
				if(strcmp(argv[i], "--notouch") == 0) {
						no_touch = true;
				}
				if(strcmp(argv[i], "--noflush") == 0) {
						no_flush = true;
				}
				if(strcmp(argv[i], "--exitflush") == 0) {
						exit_flush = true;
				}
				if(strcmp(argv[i], "--madvise") == 0) {
						do_madvise = true;
				}
				if((strcmp(argv[i], "--usec") == 0) ||
					 (strcmp(argv[i], "-s") == 0)) {
						sleep_us = atoi(argv[i + 1]);
						i++;
						continue;
				}
				if((strcmp(argv[i], "--touch") == 0) ||
					 (strcmp(argv[i], "-t") == 0)) {
						if((numTouch = atoi(argv[i + 1])) > NUM_CACHE_LINES_PER_PAGE) {
								numTouch = NUM_CACHE_LINES_PER_PAGE;
						}
						i++;
						continue;
				}
				if((strcmp(argv[i], "--pstride") == 0) ||
					 (strcmp(argv[i], "-ps") == 0)) {
						pg_stride = atoi(argv[i + 1]);
						i++;
						continue;
				}
				if((strcmp(argv[i], "--cstride") == 0) ||
					 (strcmp(argv[i], "-cs") == 0)) { 
						ca_stride = atoi(argv[i + 1]);
						i++;
						continue;
				}
				if((strcmp(argv[i], "--ncyc") == 0) ||
					 (strcmp(argv[i], "-c") == 0)) {
						numCycles = atoi(argv[i + 1]);
						i++;
						continue;
				}
				if((strcmp(argv[i], "--debug") == 0) ||
					 (strcmp(argv[i], "-d") == 0)) {
						debug_mode = true;
				}
		}

		size_t blockSize = numLines * CACHE_LINE_SIZE;
		int numPages = blockSize / PAGE_SIZE;

		if(debug_mode) {
				printf("   numLines         = %d\n", numLines);
				printf("   numPages         = %d\n", numPages);
				printf("   numCycles        = %d\n", numCycles);
				printf("   pg_stride        = %d\n", pg_stride);
				printf("   ca_stride        = %d (%d lines per page)\n", ca_stride, CEILING_POS(NUM_CACHE_LINES_PER_PAGE / (float)ca_stride));
				printf("   exclude_kernel   = %s\n", bool_to_str(exclude_kernel));
				printf("   exclude_user     = %s\n", bool_to_str(exclude_user));
				printf("   sleep_us         = %d\n", sleep_us);
				printf("   no_touch         = %s\n", bool_to_str(no_touch));
				printf("   no_flush         = %s\n", bool_to_str(no_flush));
				printf("   exit_flush       = %s\n", bool_to_str(exit_flush));
				printf("   do_madvise       = %s\n\n", bool_to_str(do_madvise));
		}

		cpu_set_t cpuset;
		pthread_t thread = pthread_self();

		CPU_ZERO(&cpuset);
		CPU_SET(0, &cpuset);

		int retval;
		if((retval = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset))) {
				printf("failed to set affinity, returned %d\n", retval);
				return EXIT_FAILURE;
		}

    struct sched_param param;
    int max_priority = sched_get_priority_max(SCHED_FIFO);
    param.sched_priority = max_priority;
    if(sched_setscheduler(0, SCHED_FIFO, &param)) {
        perror("sched_setscheduler(SCHED_FIFO)");
				return EXIT_FAILURE;
    }

		memset(&pe, 0, sizeof(struct perf_event_attr));
		//pe.type = PERF_TYPE_RAW;
		//pe.type = PERF_TYPE_HARDWARE;
		pe.type = PERF_TYPE_HW_CACHE;
		pe.size = sizeof(struct perf_event_attr);
		//pe.config = 0x4f2e;			// cache-references
		//pe.config = 0x412e;		// cache-misses
		pe.config = PERF_COUNT_HW_CACHE_LL | (PERF_COUNT_HW_CACHE_OP_WRITE << 8) | (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);
		//pe.config = PERF_COUNT_HW_CACHE_LL | (PERF_COUNT_HW_CACHE_OP_WRITE << 8) | (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);
		//pe.config = PERF_COUNT_HW_CACHE_MISSES;
		//pe.read_format = PERF_FORMAT_GROUP;
		pe.disabled = 1;
		pe.inherit = 1;
		pe.exclude_user = exclude_user;
		pe.exclude_kernel = exclude_kernel;
		pe.exclude_hv = 1;

		fd = perf_event_open(&pe, 0, -1, -1, 0);
		if (fd == -1) {
				fprintf(stderr, "Error opening leader %llx\n", pe.config);
				exit(EXIT_FAILURE);
		}

		uintptr_t block = (uintptr_t)mmap(NULL, blockSize, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		madvise((void *)block, blockSize, MADV_NOHUGEPAGE);

		if(debug_mode) {
				printf("block @ %p, block size = %zu bytes / %d lines, perf event = 0x%llx\n", (void *)block, blockSize, numLines, pe.config);
				int numAccesses = CEILING_POS(numPages / (float)pg_stride) * CEILING_POS(NUM_CACHE_LINES_PER_PAGE / (float)ca_stride);
				printf("   performing %d cache line accesses.\n", numAccesses);
		}

		/*
		if(do_madvise) {
				madvise((void *)block, blockSize, MADV_DONTNEED);
		}
		*/
		for(j = 1; j <= numCycles; j++) {
				ioctl(fd, PERF_EVENT_IOC_RESET, 0);
				ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);

				if(!no_touch) {
						#warning Using stride with striping algorithm
						register int k;
						register long * lblock;
						for(i = 0; i < numPages; i += pg_stride) {
								//register int k;
								for(k = 0; k < NUM_CACHE_LINES_PER_PAGE; k += ca_stride) {
										lblock = (long *)(block + (i * PAGE_SIZE) + (((k + i) % NUM_CACHE_LINES_PER_PAGE) * CACHE_LINE_SIZE));
										//lblock = (long *)(block + (i * PAGE_SIZE) + (k * CACHE_LINE_SIZE));
										*lblock  = 0x1122334400000000;
								}
						}

						/*
						// Seq Mode 0 (touches first two cache lines of each page)
						#warning Using "double touch" algorithm
						for(i = 0; i < numPages; i++) {
							long * lblock = (long *)(block + i * PAGE_SIZE);
							*lblock  = 0x1122334400000000;

							lblock = (long *)(block + i * PAGE_SIZE + CACHE_LINE_SIZE);
							*lblock  = 0x1122334400000000;
						}
						*/

						/*
						// Seq Mode 1 (walks pages)
						int numPages = blockSize / PAGE_SIZE;
						for(i = 0; i < numLines; i++) {
						long * lblock = (long *)(block + (i % numPages) * PAGE_SIZE + (i % NUM_LINES_PER_PAGE) * CACHE_LINE_SIZE);
						*lblock  = 0x1122334400000000;
						}
						*/

						/*
						// Seq Mode 2 (walks cache lines)
						int k;
						for(k = 0; k < numPages; k += pg_stride) {
								for(i = 0; i < NUM_CACHE_LINES_PER_PAGE; i++) {
										register long * lblock = (long *)(block + k * PAGE_SIZE + i * CACHE_LINE_SIZE);
										*lblock  = 0x1122334400000000;
								}
						}
						*/
				}
				ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);

				read(fd, &count, sizeof(uint64_t));
				printf("%lu cache misses\n", count);

				if(((j < numCycles) && !no_flush) ||
					 ((j == numCycles) && exit_flush)) {
							for(i = 0; i < numLines; i++) {
									_mm_clflush((void *)(block + i * CACHE_LINE_SIZE));
							}
				}

				if((j < numCycles) && do_madvise) {
						madvise((void *)block, blockSize, MADV_DONTNEED);
				}

				usleep(sleep_us);
		}

		close(fd);

		return EXIT_SUCCESS;
}
