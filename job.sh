#!/bin/bash

cd build
cmake ..
make
cd ../
cd script
sh submitT.sh
