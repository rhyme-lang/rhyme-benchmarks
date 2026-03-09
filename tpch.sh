#!/bin/bash

set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <USER>"
  exit 1
fi

echo "Entering directory ./tpch"
cd ./tpch

echo "Generating data for tpch"
./get_data.sh

echo "Entering directory ./tpch/pgsql"
cd ./pgsql

echo "Starting tpch benchmark for postgres"
./tpch_pgsql.sh $1

echo "Going back to ./tpch"
cd ..

echo "Entering directory ./tpch/spark/tpch-spark"
cd ./spark/tpch-spark

echo "Starting tpch benchmark for spark"
sbt package
./run.sh

echo "Going back to ./tpch"
cd ../..

echo "Entering directory ./tpch/rhyme"
cd ./rhyme

echo "Starting tpch benchmark for rhyme"
./tpch_rhyme.sh

echo "Going back to ./tpch"
cd ..
