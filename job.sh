#!/bin/bash

rm data/mydata.txt
git pull

cd build
cmake ..
make
cd ../

cd script
sh submit.sh
cd ../

cat data/mydata.txt

