#!/bin/bash

offset=
ceil=
delay=
duration=


./attack librsa.so $offset $ceil $delay $duration
./secret
wait < <(jobs -p)

