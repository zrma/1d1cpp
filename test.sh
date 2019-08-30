#!/bin/sh
cmake --version
cmake CMakeLists.txt
cmake -Dtest=ON .
make Google_Tests_run
valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=med --track-origins=yes --vgdb=no ./test/Google_Tests_run
make clean
rm ./CMakeCache.txt
