#!/bin/sh

THREAD_NUM=$1
EXE_FILE="./build/a.out"
OUT_DIR="./records"

if [ ! -d $OUT_DIR ]; then
    mkdir $OUT_DIR
fi

for ((i=0; i<$THREAD_NUM; i++)) do
    nohup $EXE_FILE "${OUT_DIR}/output_${i}.txt" &
done