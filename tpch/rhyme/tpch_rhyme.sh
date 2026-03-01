#!/bin/bash

mkdir -p out
mkdir -p cgen-sql

cp -v ../../rhyme/cgen-sql/rhyme-c.h ./cgen-sql

node tpch.js
python3 tpch_bench.py

