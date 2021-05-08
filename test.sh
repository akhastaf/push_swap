#!/bin/sh
for i in {1..100}
do
    ARG=$(./r.py 100) ; ./push_swap $ARG | wc -l
done