#!/bin/sh
cmake --version
cmake CMakeLists.txt
cmake -Dtest=ON .
make Google_Tests_run
./test/Google_Tests_run
make clean
rm ./CMakeCache.txt
