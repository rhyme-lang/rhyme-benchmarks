#!/bin/bash

mkdir -p out
mkdir -p cgen-sql

cp -v ../../rhyme/cgen-sql/rhyme-c.h cgen-sql

mkdir -p third-party/yyjson
cp -v -r ../../rhyme/third-party/yyjson/. third-party/yyjson
make -C third-party/yyjson

node json-bench-c.js

python3 json_bench.py

