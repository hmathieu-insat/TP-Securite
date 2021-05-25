#!/bin/bash

e= 5
offset=5211
ceil=140
delay=10000
duration=10000000000


> result.csv
for i in {1..100}
do
	./attack librsa.so $offset $ceil $delay $duration >> result.csv &
	./victim 54244432 $e 414603367

	wait < <(jobs -p)
done

echo 'mean'
awk '{ total += $0 } END { print total/NR }' result.csv
echo 'standard deviation'
awk '{x+=$0;y+=$0^2}END{print sqrt(y/NR-(x/NR)^2)}' result.csv
