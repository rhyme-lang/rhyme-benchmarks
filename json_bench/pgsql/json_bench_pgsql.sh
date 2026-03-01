#!/bin/bash

USER=$1

psql -d json_bench -U $USER -f ddl.sql
psql -d json_bench -c "\COPY bluesky FROM '../data/bluesky.json' WITH (format csv, quote e'\x01', delimiter e'\x02', escape e'\x01');"

python3 bench.py $USER .

