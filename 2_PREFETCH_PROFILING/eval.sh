#!/bin/bash

fun_array=(0 1 2 3 4 5 6)

> result.csv
for k in {0..63}
do
	mean_array=()
	for j in ${fun_array[@]};
	do
		> part.awk
		for i in {1..100}
		do
			./profiling $j $k >> part.awk #Replace ? by the variable name (i, j or k) 
		done
		mean_float=$(awk '{ total += $0 } END {  print total/NR }' part.awk)
		mean_int=${mean_float%.*}
		mean_array+=($mean_int)
	done
	echo ${mean_array[@]} >> result.csv
done

