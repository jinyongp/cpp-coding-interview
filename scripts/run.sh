#!/usr/bin/env bash

bin=build/examples

if [ -z "$file" ]; then
  command=$(basename $0 .sh)
  echo "Usage: $command file=<file>"
  echo "Available files:"
  find $bin -type f | awk -F/ '{print "\t" $(NF)}'
  exit 1
fi

cd $(dirname $0)/..

exectuable=$(find $bin -name $file)
if [ -z "$exectuable" ]; then
  echo "$1 not found"
  exit 1
fi

$exectuable
