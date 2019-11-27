#!/bin/bash
# perf stat -e instructions,cycles -p 27465
# perf stat -e mem_load_retired.l3_hit,mem_load_retired.l3_miss,mem_inst_retired.all_loads -p 27465
# perf stat -e IDQ_UOPS_NOT_DELIVERED.CORE,UOPS_ISSUED.ANY,UOPS_RETIRED.RETIRE_SLOTS,INT_MISC.RECOVERY_CYCLES,CPU_CLK_UNHALTED.THREAD -p 30058

#perf stat -I 120000 -e mem_load_retired.l3_hit,mem_load_retired.l3_miss,instructions,cycles -p 23903

PID=$1
stage=$2
if [ stage -eq 1 ]
then
    perf stat -I 1000 -e IDQ_UOPS_NOT_DELIVERED.CORE,UOPS_ISSUED.ANY,UOPS_RETIRED.RETIRE_SLOTS -p $PID
else
    perf stat -I 1000 -e INT_MISC.RECOVERY_CYCLES,CPU_CLK_UNHALTED.THREAD -p $PID
fi
