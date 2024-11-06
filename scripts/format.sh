#!/usr/bin/env bash

cd "$(dirname "$0")/.."

if command -v clang-format > /dev/null; then
  find -E src -regex '.*\.(h|cc)' -exec clang-format -i {} \;
else
  echo "[ERROR] clang-format is not installed. Please install clang-format to use this command."
fi
