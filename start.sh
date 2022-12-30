#!/bin/sh

OUT_NAME=$1
THREAD_NUM=$2
EXE_FILE="./build/a.out"
OUT_DIR="./records/${OUT_NAME}"

if [ ! -d "./records" ]; then
    mkdir "./records"
fi

if [ ! -d $OUT_DIR ]; then
    mkdir $OUT_DIR
fi

for ((i=0; i<$THREAD_NUM; i++)) do
    nohup $EXE_FILE "${OUT_DIR}/output_${i}.txt" &
done