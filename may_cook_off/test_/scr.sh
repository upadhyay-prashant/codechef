#!/bin/bash -xe
time python test.py > out.1
#./test < out.1 > out.2
#./convert < out.2 > out.3
time ./run < out.1 > out.2

