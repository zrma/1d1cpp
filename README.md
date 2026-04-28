# 1d1cpp

1 day 1 coding with c++

[![CI](https://github.com/zrma/1d1cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/zrma/1d1cpp/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/zrma/1d1cpp/branch/master/graph/badge.svg)](https://codecov.io/gh/zrma/1d1cpp)

## Build

```sh
git submodule update --init --recursive
cmake -S . -B cmake-build-local -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-local --target Google_Tests_run --parallel
ctest --test-dir cmake-build-local --output-on-failure
```

For the same flow with an optional Valgrind pass:

```sh
./test.sh
```
