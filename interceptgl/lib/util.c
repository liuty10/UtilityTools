#include "util.h"

int 	thr_ctx_idx1 = 0;
int 	pfm_init_flag = -1;
int      perfstart_flag = 0; 
uint64_t count[NUM_COUNTERS];
thread_pfm_context_t thread_ctxs[MAX_NUM_THREADS];

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

void perf_start(){
    	if(perfstart_flag == 0){
		/* initialize PMU monitoring */
                if(pfm_init_flag != 0){
                   pfm_init_flag = pfm_operations_init();
                   if(pfm_init_flag != 0 ) errx(1, "PMU initialization failed\n");
                }
		thread_ctxs[0].tid = 0;
        	thread_ctxs[0].fds = NULL;
        	thread_ctxs[0].num_fds = 0;
                char *evns = getenv("PFM_EVENTS");
                if(evns == NULL) evns="instructions,cycles"; 
		int ret = perf_setup_list_events(evns, &(thread_ctxs[0].fds),
		                                   &(thread_ctxs[0].num_fds));
		if(ret || !(thread_ctxs[0].num_fds))
			return;

		for(int j = 0; j < thread_ctxs[0].num_fds; j++){
		   thread_ctxs[0].fds[j].hw.disabled = 1;
		   thread_ctxs[0].fds[j].hw.exclude_user = 0;
		   thread_ctxs[0].fds[j].hw.exclude_kernel = 0;
		   thread_ctxs[0].fds[j].hw.exclude_hv = 1;
		   thread_ctxs[0].fds[j].hw.inherit = 0; /* only monitor the current thread */
		   thread_ctxs[0].fds[j].fd = perf_event_open(&(thread_ctxs[0].fds[j].hw), 
							        thread_ctxs[0].tid, -1, -1, 0);
		   if (thread_ctxs[0].fds[j].fd == -1) {
		           warn("cannot attach event%d %s to thread [%d]: ", j,
		                thread_ctxs[0].fds[j].name, thread_ctxs[0].tid);
		           return;
		   }
		   DPRINTF("PMU context opened for thread [%d]\n", thread_ctxs[0].tid);
		}
        }
        perfstart_flag++;
        //if(perfstart_flag == 3) perfstart_flag = 1;
        if(perfstart_flag == thr_ctx_idx1+2) perfstart_flag = 1;

	for(int i = 0; i < thread_ctxs[perfstart_flag-1].num_fds; i++){
		ioctl(thread_ctxs[perfstart_flag-1].fds[i].fd, PERF_EVENT_IOC_RESET, 0);
		ioctl(thread_ctxs[perfstart_flag-1].fds[i].fd, PERF_EVENT_IOC_ENABLE, 0);
	}
}

void perf_end(){
    	if(perfstart_flag != 0){
		for(int i = 0; i < thread_ctxs[perfstart_flag-1].num_fds; i++){
		    ioctl(thread_ctxs[perfstart_flag-1].fds[i].fd, PERF_EVENT_IOC_DISABLE, 0);
		    read (thread_ctxs[perfstart_flag-1].fds[i].fd, &count[i], sizeof(uint64_t));
		    fprintf(stderr, "thread%d : event%d : %ld, totla thread:%d, addr: %p\n",perfstart_flag-1,i,count[i],thr_ctx_idx1, &thr_ctx_idx1);
		}
        }else{
		MY_LOG(" Perf didn't start, START FIRST\n");
        }
}

