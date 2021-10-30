#!/bin/bash

cd ../build

export MKL_ENABLE_INSTRUCTIONS=AVX2
export MKL_NUM_THREADS=1

./verify &> ../data/mydata.txt

