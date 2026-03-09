#!/bin/bash

set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <USER>"
  exit 1
fi

echo "Entering directory ./json_bench"
cd ./json_bench

echo "Generating data for json_bench"
./get_bluesky.sh

echo "Entering directory ./json_bench/pgsql"
cd ./pgsql

echo "Starting json_bench benchmark for postgres"
./json_bench_pgsql.sh $1

echo "Going back to ./json_bench"
cd ..

echo "Entering directory ./json_bench/duckdb"
cd ./duckdb

echo "Starting json_bench benchmark for duckdb"
./json_bench_duckdb.sh

echo "Going back to ./json_bench"
cd ..

echo "Entering directory ./json_bench/rhyme"
cd ./rhyme

echo "Starting json_bench benchmark for rhyme"
./json_bench_rhyme.sh

echo "Going back to ./json_bench"
cd ..
