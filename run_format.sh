#!/bin/bash
find src/ test/ include/ctci -type f -name "*.[h|c]pp" | xargs -I {} clang-format -i --style=file {}
