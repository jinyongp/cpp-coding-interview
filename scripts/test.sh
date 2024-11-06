#!/usr/bin/env bash

cd "$(dirname "$0")/.."

if [[ -z "$name" ]]; then
  name="*"
elif [[ "$name" != *.* ]]; then
  name="${name}.*"
fi

./build/main --gtest_brief=1 --gtest_filter="$name"
