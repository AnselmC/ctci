#!/bin/bash

# run clang-format
chmod +x run_format.sh
./run_format.sh
dirty=$(git ls-files --modified)
if [[ $dirty ]]; then
	echo "Formatting incorrect"
	exit 1
fi;
# run git files-changed
# if files changed, fail

# adapted from: https://github.com/codecov/example-cpp11-cmake/blob/master/build.sh
set -euo pipefail

mkdir -p build && cd build

# Configure
cmake -DCODE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
# Build (for Make on Unix equivalent to `make -j $(nproc)`)
cmake --build . --config Debug -- -j $(nproc)
# Test
ctest -j $(nproc) --output-on-failure
