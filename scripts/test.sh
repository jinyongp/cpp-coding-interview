#!/usr/bin/env bash

cd "$(dirname "$0")/.."

if [[ -z "$filter" ]]; then
  filter="*"
elif [[ "$filter" != *.* ]]; then
  filter="${filter}.*"
fi

./build/main --gtest_brief=1 --gtest_filter="$filter"
