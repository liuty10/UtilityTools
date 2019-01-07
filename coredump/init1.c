#include<stdio.h>
#define _GNU_SOURCE             /*  See feature_test_macros(7) */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>
#include <sched.h>
#include <sys/mman.h>

int main(){
  int cpuid = 0;
  pid_t pid = getpid();
  cpu_set_t set;
  CPU_ZERO(&set);
  CPU_SET(cpuid, &set);
  if (sched_setaffinity(pid, sizeof(set), &set) == -1){
    fprintf(stderr, “sched_setaffinity failed\n”);
    exit(0);
  }else{
    fprintf(stderr, “binding cpu %d\n”, cpuid);
  }
  char *ptr = (char*)malloc(1024*4*1024);
  int i;
  for(i=0;i<1024*4*1024;i++)
    *(ptr+i)='a';
  return 0;
}
