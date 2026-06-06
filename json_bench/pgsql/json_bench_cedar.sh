#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <user>"
  exit 1
fi

USER=$1

psql -U $USER -f ddl.sql
psql -U $USER -c "\COPY bluesky FROM '../data/bluesky.json' WITH (format csv, quote e'\x01', delimiter e'\x02', escape e'\x01');"

python3 bench_cedar.py $USER .

