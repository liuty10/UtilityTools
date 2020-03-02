#include "util.h"
#define NUM_THREADS 6

#define NUM_COUNTERS 4
static int       perfstart_flag = 0; 
static uint64_t  count[NUM_COUNTERS];
static perf_event_desc_t * fds=NULL;

thread_pfm_context_t thread_ctx;

/*
 * Initilization
 * Paramters:
 *      NONE
 * Retun value:
 * Return value:
 *      0       --> success
 *      other   --> failed
 */
int pfm_operations_init()
{
  if (pfm_initialize() != PFM_SUCCESS)
    {
      warnx("libpfm initialization failed");
      return -1;
    }

  //thr_ctx_idx = 0;

  return 0;
}


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

/*static long
perf_event_open(struct perf_event_attr *hw_event, pid_t pid,
		int cpu, int group_fd, unsigned long flags)
{
	int ret;
	ret = syscall(__NR_perf_event_open, hw_event, pid, cpu,
					group_fd, flags);
	return ret;
}*/

void perf_start(char * evns, pid_t tid){
    	if(perfstart_flag == 0){
		/* initialize PMU monitoring */
       		int ret = pfm_operations_init();
       		if(ret != 0 )
       		        errx(1, "PMU initialization failed\n");

		thread_ctx.tid = 0;
        	thread_ctx.fds = NULL;
        	thread_ctx.num_fds = 0;

	        ret = perf_setup_list_events(evns, &(thread_ctx.fds),
	                               &(thread_ctx.num_fds));
	        if(ret || !(thread_ctx.num_fds))
	        	return;

                fds = thread_ctx.fds;
		for(int i = 0; i < thread_ctx.num_fds; i++){
		        fds[i].hw.disabled = 1;
		        fds[i].hw.exclude_user = 0;
		        fds[i].hw.exclude_kernel = 0;
		        fds[i].hw.exclude_hv = 1;
		        //fds[i].hw.read_format = PERF_FORMAT_SCALE;
		        fds[i].hw.inherit = 0; /* only monitor the current thread */
		
		        fds[i].fd = perf_event_open(&fds[i].hw, thread_ctx.tid, -1, -1, 0);
		        if (fds[i].fd == -1) {
		                warn("cannot attach event%d %s to thread [%d]: ", i,
		                     fds[i].name, thread_ctx.tid);
		                return;
		        }
		        DPRINTF("PMU context opened for thread [%d]\n", thread_ctx.tid);
		}
        }
        perfstart_flag += 1;
        if(perfstart_flag == 7) perfstart_flag = 1;
	for(int i = 0; i < thread_ctx.num_fds; i++){
		ioctl(fds[i].fd, PERF_EVENT_IOC_RESET, 0);
		ioctl(fds[i].fd, PERF_EVENT_IOC_ENABLE, 0);
	}
}

void perf_end(){
    	if(perfstart_flag != 0){
		for(int i = 0; i < thread_ctx.num_fds; i++){
			ioctl(fds[i].fd, PERF_EVENT_IOC_DISABLE, 0);
			read(fds[i].fd, &count[i], sizeof(uint64_t));
			MY_LOG("%ld\n",count[i]);
		}
        }else{
		MY_LOG(" Perf didn't start, START FIRST\n");
        }
}


