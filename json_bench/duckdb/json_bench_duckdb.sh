#!/bin/bash

USER=$1

duckdb ./json_bench.db -f ddl.sql

duckdb ./json_bench.db -c "insert into bluesky select * from read_ndjson_objects('../data/bluesky.json', ignore_errors=false, maximum_object_size=1048576000);"

python3 bench.py

