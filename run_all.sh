#!/bin/bash

set -e

if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Usage: $0 <USER> <GITHUB_TOKEN>"
  exit 1
fi

echo "=== Running TPC-H benchmarks ==="
./tpch.sh $1

echo "=== Running JSONBench benchmarks ==="
./json_bench.sh $1

echo "=== Running Additional benchmarks ==="
./additional.sh $2

