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

#ifdef _MSC_VER
#include <intrin.h> /*   for rdtscp and clflush */
#pragma optimize("gt",on)
#else
#include <x86intrin.h> /*   for rdtscp and clflush */
#endif


#define CACHE_LINE_SIZE 64
#define NUM_LINES 1000000

		static long
perf_event_open(struct perf_event_attr *hw_event, pid_t pid,
				int cpu, int group_fd, unsigned long flags)
{
		int ret;

		ret = syscall(__NR_perf_event_open, hw_event, pid, cpu,
						group_fd, flags);
		return ret;
}

static inline void wbinvd(void){
    asm volatile("wbinvd");
    asm volatile("sfence\n\t"
                    :
                    :
                    : "memory");
}


int main(int argc, char **argv)
{
		struct perf_event_attr pe;
		uint64_t count;
		int fd, i;

		cpu_set_t cpuset;
		pthread_t thread = pthread_self();

		CPU_ZERO(&cpuset);
		CPU_SET(0, &cpuset);

		int retval;
		if((retval = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset))) {
				printf("thread failed to set affinity, returned %d\n", retval);
				pthread_exit(NULL);
		}

		memset(&pe, 0, sizeof(struct perf_event_attr));
		//pe.type = PERF_TYPE_RAW;
		//pe.type = PERF_TYPE_HARDWARE;
		pe.type = PERF_TYPE_HW_CACHE;
		pe.size = sizeof(struct perf_event_attr);
		//pe.config = 0x412e;
		pe.config = PERF_COUNT_HW_CACHE_LL | (PERF_COUNT_HW_CACHE_OP_WRITE << 8) | (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);
		//pe.config = PERF_COUNT_HW_CACHE_MISSES;
		//pe.read_format = PERF_FORMAT_GROUP;
		pe.disabled = 1;
		pe.inherit = 1;
		pe.exclude_user = 0;
		pe.exclude_kernel = 1;
		pe.exclude_hv = 1;
		pe.exclude_callchain_user = 0;
		pe.exclude_callchain_kernel = 1;

		fd = perf_event_open(&pe, 0, -1, -1, 0);
		if (fd == -1) {
				fprintf(stderr, "Error opening leader %llx\n", pe.config);
				exit(EXIT_FAILURE);
		}

		uintptr_t block = (uintptr_t)mmap(NULL, NUM_LINES * CACHE_LINE_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		printf("block = %p\n", (void *)block);

		long seed = time(NULL);

		ioctl(fd, PERF_EVENT_IOC_RESET, 0);
		ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);

		for(i = 0; i < NUM_LINES; i++) {
				seed = ((seed * 167) + 13) % NUM_LINES;
				//seed = i;
				long * lblock = (long *)(block + seed * CACHE_LINE_SIZE);
				
				*lblock  = 0x1122334400000000;
	      _mm_clflush(lblock);	
		}

		/*
		for(i = 0; i < NUM_LINES; i++) {
				seed = ((seed * 167) + 13) % NUM_LINES;
				//seed = i;
				long readval = *(long *)(block + seed * CACHE_LINE_SIZE);
		}
		*/
		ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
    
    /*
		struct read_format {
				long nr;            // The number of events
				long time_enabled;  // if PERF_FORMAT_TOTAL_TIME_ENABLED
				long time_running;  // if PERF_FORMAT_TOTAL_TIME_RUNNING
				struct {
						long value;     // The value of the event
						long id;        // if PERF_FORMAT_ID
				} values[nr];
		}
		*/

		int readbytes = 0;
		uint64_t buf[16];
		readbytes = read(fd, &buf, 5 * sizeof(uint64_t));
		perror("read");
		printf("%lu cache misses\n", buf[0]);
		printf("time enabled = %lu\n", buf[1]);
		printf("time running = %lu\n", buf[2]);
		printf("   value = %lu\n", buf[3]);
		printf("   id = %lu\n", buf[4]);
		printf("first read amount = %d\n", readbytes);
		close(fd);

		seed = time(NULL);

		fd = perf_event_open(&pe, 0, -1, -1, 0);
		ioctl(fd, PERF_EVENT_IOC_RESET, 0);
		ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);

		for(i = 0; i < NUM_LINES; i++) {
				seed = ((seed * 167) + 13) % NUM_LINES;
				//seed = i;
				long * lblock = (long *)(block + seed * CACHE_LINE_SIZE);
				
				*lblock  = 0x1122334400000000;
		}

		/*
		for(i = 0; i < NUM_LINES; i++) {
				seed = ((seed * 167) + 13) % NUM_LINES;
				//seed = i;
				long readval = *(long *)(block + seed * CACHE_LINE_SIZE);
		}
		*/
		ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);

		readbytes = 0;
		readbytes = read(fd, &buf, 5 * sizeof(uint64_t));
		perror("read");
		printf("%lu cache misses\n", buf[0]);
		printf("time enabled = %lu\n", buf[1]);
		printf("time running = %lu\n", buf[2]);
		printf("   value = %lu\n", buf[3]);
		printf("   id = %lu\n", buf[4]);
		printf("first read amount = %d\n", readbytes);


		close(fd);
}
