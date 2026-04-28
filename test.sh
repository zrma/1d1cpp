#!/bin/sh
set -eu

BUILD_DIR="${BUILD_DIR:-cmake-build-local}"
CMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE:-Debug}"
ENABLE_COVERAGE="${ENABLE_COVERAGE:-OFF}"

cmake --version

if [ -n "${CMAKE_GENERATOR:-}" ]; then
    cmake -S . -B "$BUILD_DIR" -G "$CMAKE_GENERATOR" \
        -DCMAKE_BUILD_TYPE="$CMAKE_BUILD_TYPE" \
        -DENABLE_COVERAGE="$ENABLE_COVERAGE"
else
    cmake -S . -B "$BUILD_DIR" \
        -DCMAKE_BUILD_TYPE="$CMAKE_BUILD_TYPE" \
        -DENABLE_COVERAGE="$ENABLE_COVERAGE"
fi

cmake --build "$BUILD_DIR" --target Google_Tests_run --parallel
ctest --test-dir "$BUILD_DIR" --output-on-failure

if command -v valgrind >/dev/null 2>&1; then
    valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=med \
        --track-origins=yes --vgdb=no "$BUILD_DIR/test/Google_Tests_run"
else
    echo "valgrind not found; skipping leak check"
fi
