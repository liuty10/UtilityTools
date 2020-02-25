#include "util.h"
        
static int       perfstart_flag = 0; 
static uint64_t  count1, count2;
static int 	 fd1, fd2;

long long gettime_nanoTime(void)
{
    struct timespec __tv;
    clock_gettime(CLOCK_MONOTONIC,&__tv);
    return(long long)(__tv.tv_sec * 1e9 + __tv.tv_nsec);
}

void
MY_TRACE (void)
{
  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);

  MY_LOG ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     MY_LOG ("%s\n", strings[i]);

  free (strings);
}

static long
perf_event_open(struct perf_event_attr *hw_event, pid_t pid,
		int cpu, int group_fd, unsigned long flags)
{
	int ret;
	ret = syscall(__NR_perf_event_open, hw_event, pid, cpu,
					group_fd, flags);
	return ret;
}

void perf_start(){
	static struct    perf_event_attr pe1;
	static struct    perf_event_attr pe2;
    	if(perfstart_flag == 0){
                perfstart_flag = 1;

		memset(&pe1, 0, sizeof(struct perf_event_attr));
		pe1.type = PERF_TYPE_HARDWARE;
		pe1.size = sizeof(struct perf_event_attr);
		pe1.config = PERF_COUNT_HW_INSTRUCTIONS;
		pe1.disabled = 1;
		pe1.exclude_user = 0;
		pe1.exclude_kernel = 1;
		pe1.exclude_hv = 1;		
		fd1 = perf_event_open(&pe1, 0, -1, -1, 0);
		if (fd1 == -1) {
		    MY_LOG("Error opening leader %llx\n", pe1.config);
	            exit(EXIT_FAILURE);
		}

		memset(&pe2, 0, sizeof(struct perf_event_attr));
		pe2.type = PERF_TYPE_HARDWARE;
		pe2.size = sizeof(struct perf_event_attr);
		pe2.config = PERF_COUNT_HW_CPU_CYCLES;
		pe2.disabled = 1;
		pe2.exclude_user = 0;
		pe2.exclude_kernel = 1;
		pe2.exclude_hv = 1;
		fd2 = perf_event_open(&pe2, 0, -1, -1, 0);
		if (fd2 == -1) {
		    MY_LOG("Error opening leader %llx\n", pe2.config);
	            exit(EXIT_FAILURE);
		}
        }
	ioctl(fd1, PERF_EVENT_IOC_RESET, 0);
	ioctl(fd1, PERF_EVENT_IOC_ENABLE, 0);
	ioctl(fd2, PERF_EVENT_IOC_RESET, 0);
	ioctl(fd2, PERF_EVENT_IOC_ENABLE, 0);
}

void perf_end(){
    	if(perfstart_flag == 1){
		ioctl(fd1, PERF_EVENT_IOC_DISABLE, 0);
		ioctl(fd2, PERF_EVENT_IOC_DISABLE, 0);
		read(fd1, &count1, sizeof(uint64_t));
		read(fd2, &count2, sizeof(uint64_t));
		MY_LOG("Instructions = %ld, Cycles = %ld, IPC: %lf\n", count1, count2, (float)count1/(float)count2);
        }else{
		MY_LOG(" Perf didn't start, START FIRST\n");
        }
}


