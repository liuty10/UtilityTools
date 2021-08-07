rm ./*.out

cat RE_NoReg_rowbuffer.log | grep CYCLES | awk '{print $3}' | tr -d ',' > CYCLES.out
cat RE_NoReg_rowbuffer.log | grep INSTRUCTION | awk '{print $3}' | tr -d ',' > INSTRUCTION.out
cat RE_NoReg_rowbuffer.log | grep ALL | awk '{print $3}' | tr -d ',' > ALL.out
cat RE_NoReg_rowbuffer.log | grep RD | awk '{print $3}'  | tr -d ',' > RD.out
cat RE_NoReg_rowbuffer.log | grep WR | awk '{print $3}'  | tr -d ',' > WR.out
cat RE_NoReg_rowbuffer.log | grep BYP | awk '{print $3}' | tr -d ',' > BYP.out

paste {CYCLES,INSTRUCTION}.out | awk '{ print $2 / $1; }' > IPC.out
paste {ALL,RD,WR,BYP}.out | awk '{ print ($1-$2-$3-$4) / $1; }' > RowBufferHit.out

echo "CAS_ALL,ACT_RD,ACT_WR,ACT_BYP,CYCLES,INSTRUCTIONS,IPC,RowBufferHit" > RE_NoReg_rowbuffer.csv
paste -d, {ALL,RD,WR,BYP,CYCLES,INSTRUCTION,IPC,RowBufferHit}.out >> RE_NoReg_rowbuffer.csv

rm ./*.out

