#include "util.h"

int 	 thr_ctx_idx = 0;
int 	 pfm_init_flag = -1;
int      perfstart_flag = 0; 
int	 perf_iterations = 1;
int 	 cur_iteration = 0;
uint64_t count[NUM_COUNTERS];
thread_pfm_context_t thread_ctxs[MAX_NUM_THREADS];
pid_t glx_pid = 0;
FILE* glxLogFp = NULL;
struct fd_pair *headerfd = NULL;

FILE* getLogFilePointer(pid_t cur_pid){
     struct fd_pair *tmpfd = headerfd;
     struct fd_pair *lstfd = NULL;
     int try_find = 0;

     char str1[10];
     char logpath[80] ={'/','t','m','p','/','v','g','l','/'};

     while(tmpfd!=NULL){
         if(tmpfd->pid != cur_pid){
             lstfd = tmpfd;
             tmpfd = tmpfd->next;
             try_find = 1;
         }else{
             return tmpfd->fd;
         }
     }
     if(tmpfd == NULL){
          tmpfd = (struct fd_pair*)malloc(sizeof(struct fd_pair));
          tmpfd->pid = cur_pid;
          sprintf(str1, "%d", cur_pid);
          strcat(logpath, str1);
          tmpfd->fd = fopen(logpath, "ab+");
          tmpfd->status = 1;
          tmpfd->next = NULL;
          if(try_find == 0){
             headerfd = tmpfd;
          }else{
             lstfd->next = tmpfd;
          }
          return (tmpfd->fd!=NULL)?tmpfd->fd:NULL;
     }
}

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
		thread_ctxs[0].tid = syscall( __NR_gettid );
        	thread_ctxs[0].fds = NULL;
        	thread_ctxs[0].num_fds = 0;
                char *evns = getenv("PFM_EVENTS");
                if(evns == NULL) evns="instructions,cycles,LLC_MISSES,LLC_REFERENCES"; 
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
							        0, -1, -1, 0);
		   if (thread_ctxs[0].fds[j].fd == -1) {
		           warn("cannot attach event%d %s to thread [%d]: ", j,
		                thread_ctxs[0].fds[j].name, thread_ctxs[0].tid);
		           return;
		   }
		   DPRINTF("PMU context opened for thread [%d]\n", thread_ctxs[0].tid);
		}
                perf_iterations = ((thread_ctxs[0].num_fds-1)/4)+1;
        }
        perfstart_flag++;
        if(perfstart_flag == thr_ctx_idx+2) perfstart_flag = 1;
         
	//for(int i = 0; i < thread_ctxs[perfstart_flag-1].num_fds; i++){
	for(int i = 0; i < 4; i++){
	    ioctl(thread_ctxs[perfstart_flag-1].fds[cur_iteration*4+i].fd, PERF_EVENT_IOC_RESET, 0);
	    ioctl(thread_ctxs[perfstart_flag-1].fds[cur_iteration*4+i].fd, PERF_EVENT_IOC_ENABLE, 0);
	}
}

void perf_end(){
    	if(perfstart_flag != 0){
	    //for(int i = 0; i < thread_ctxs[perfstart_flag-1].num_fds; i++){
	    for(int i = 0; i < 4; i++){
	        ioctl(thread_ctxs[perfstart_flag-1].fds[cur_iteration*4+i].fd,PERF_EVENT_IOC_DISABLE,0);
	        read(thread_ctxs[perfstart_flag-1].fds[cur_iteration*4+i].fd,&count[i],sizeof(uint64_t));
	    }
	    if(glx_pid == 0){
	        glx_pid = getpid();
	        glxLogFp = getLogFilePointer(glx_pid);
	    }
	    fprintf(glxLogFp, "%dnd threadid: %d : event%d-event%d: %ld, %ld, %ld, %ld\n",
                    perfstart_flag-1, thread_ctxs[perfstart_flag-1].tid, 
                    cur_iteration*4, cur_iteration*4+3,
	            count[0], count[1], count[2], count[3]);

       	    cur_iteration++;
       	    if(cur_iteration == perf_iterations){
       	        cur_iteration = 0;
       	    }
        }else{
		MY_LOG(" Perf didn't start, START FIRST\n");
        }
}

