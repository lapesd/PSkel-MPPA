#!/bin/bash
set -e

for NUMBER_ITERATIONS in 1000 10000
do
	make -f makefile clean
	make -f makefile CFLAGS=-DITERATIONS=${NUMBER_ITERATIONS}
	for NUMBER_CLUSTERS in 2 4 6 8 10 12 14 16
	do
		./run.sh ${NUMBER_CLUSTERS} | tee -a ./exec_time_128_128_${NUMBER_CLUSTERS}_${NUMBER_ITERATIONS}.txt
		sleep 1
	done
done

