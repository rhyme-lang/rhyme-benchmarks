#!/bin/bash

set -e

if [ ! -d tpch-dbgen ] ; then
  git clone https://github.com/electrum/tpch-dbgen.git
fi

cd tpch-dbgen
make

./dbgen -vf -s 10
chmod 664 *.tbl

rm -rf ../data
mkdir ../data

mv -v *.tbl ../data

