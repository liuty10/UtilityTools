//perf stat -e IDQ_UOPS_NOT_DELIVERED.CORE,UOPS_ISSUED.ANY,UOPS_RETIRED.RETIRE_SLOTS,INT_MISC.RECOVERY_CYCLES,UOPS_RETIRED.RETIRE_SLOTS,CPU_CLK_UNHALTED.THREAD -p 30521
// perf stat -e LLC-load-misses,LLC-Loads,instructions,cycles -p PID

#include<stdio.h>
int main(){
   printf("hello\n");
   return 0;
}
