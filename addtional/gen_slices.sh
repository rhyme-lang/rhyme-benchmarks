#!/bin/bash
DATA_DIR=./data
mkdir -p $DATA_DIR/sliced
for n in $(seq 0 1000 10000); do
    echo $n
    head -n $n $DATA_DIR/commits.json > $DATA_DIR/sliced/commits_${n}.json
done
echo "Created $(ls $DATA_DIR/sliced/commits_*.json | wc -l) slice files."
