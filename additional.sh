#!/bin/bash

set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <GITHUB_TOKEN>"
  exit 1
fi

echo "Entering directory ./additional"
cd ./additional

echo "Fetching commits data"
./get_commits.sh $1

echo "Generating slices"
./gen_slices.sh

echo "Entering directory ./additional/jq"
cd ./jq

echo "Starting additional benchmark for jq"
python3 bench.py

echo "Going back to ./additional"
cd ..

echo "Entering directory ./additional/rhyme"
cd ./rhyme

echo "Starting additional benchmark for rhyme"
./bench.sh

echo "Running end-to-end execution time analysis"
python3 compile_bench.py

echo "Going back to ./additional"
cd ..
