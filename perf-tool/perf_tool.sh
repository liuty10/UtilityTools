#!/bin/bash
# perf stat -e instructions,cycles -p 27465
# perf stat -e mem_load_retired.l3_hit,mem_load_retired.l3_miss,mem_inst_retired.all_loads -p 27465
# perf stat -e IDQ_UOPS_NOT_DELIVERED.CORE,UOPS_ISSUED.ANY,UOPS_RETIRED.RETIRE_SLOTS,INT_MISC.RECOVERY_CYCLES,CPU_CLK_UNHALTED.THREAD -p 30058

# perf stat -I 120000 -e mem_load_retired.l3_hit,mem_load_retired.l3_miss,instructions,cycles -p 23903

# perf stat -I 120000 -e resource_stalls.any,resource_stalls.sb -p 23903

# perf stat -I 120000 -e resource_stalls.any,resource_stalls.sb -p 18269
# perf stat -I 120000 -e cycle_activity.stalls_l1d_miss,cycle_activity.stalls_l2_miss,cycle_activity.cycles_l3_miss,cycle_activity.stalls_mem_any -p 18269

# perf stat -I 120000 -e resource_stalls.any,resource_stalls.sb,cycle_activity.stalls_l1d_miss,cycle_activity.stalls_l2_miss,cycle_activity.stalls_mem_any -p 18269

######################################################
# perf stat -I 120000 -e instructions,cycles,mem_load_retired.l3_miss,mem_load_retired.l3_hit -t 22801
# perf stat -I 120000 -e IDQ_UOPS_NOT_DELIVERED.CORE,UOPS_ISSUED.ANY,UOPS_RETIRED.RETIRE_SLOTS,INT_MISC.RECOVERY_CYCLES,CPU_CLK_UNHALTED.THREAD -t 22744
# perf stat -I 120000 -e resource_stalls.any,resource_stalls.sb -t 22743
# perf stat -I 120000 -e cycle_activity.stalls_l1d_miss,cycle_activity.stalls_l2_miss,cycle_activity.cycles_l3_miss,cycle_activity.stalls_mem_any -t 22792
# perf stat -I 120000 -e instructions,cycles,L1-dcache-loads,L1-dcache-load-misses -t 22801
# perf stat -I 120000 -e dTLB-loads,dTLB-load-misses,iTLB-loads,iTLB-load-misses -t 22801
# perf stat -I 120000 -e branch-instructions,branch-misses,context-switches,cpu-migrations -t 22801
#
#

PID=$1
stage=$2
if [ stage -eq 1 ]
then
    perf stat -I 1000 -e IDQ_UOPS_NOT_DELIVERED.CORE,UOPS_ISSUED.ANY,UOPS_RETIRED.RETIRE_SLOTS -p $PID
else
    perf stat -I 1000 -e INT_MISC.RECOVERY_CYCLES,CPU_CLK_UNHALTED.THREAD -p $PID
fi
