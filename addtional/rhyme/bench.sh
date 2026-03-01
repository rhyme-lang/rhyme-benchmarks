#!/bin/bash

mkdir -p out
mkdir -p cgen-sql

cp -v ../../rhyme/cgen-sql/rhyme-c.h cgen-sql

mkdir -p third-party/yyjson
cp -v -r ../../rhyme/third-party/yyjson third-party/
make -C third-party/yyjson

#node --max-old-space-size=16384 rhyme-bench.js 6 1
node rhyme-bench-c.js

python3 bench.py


