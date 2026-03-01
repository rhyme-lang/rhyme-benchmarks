#!/bin/bash

USER=$1

cd ./tpch-pgsql

echo "Creating python venv"
rm -rf venv

python3 -m venv venv
source ./venv/bin/activate

echo "Installing python packages"
pip3 install -r requirements.txt

python3 tpch_pgsql.py -b -g ../../tpch-dbgen -s 10 -U $USER prepare
python3 tpch_pgsql.py -b -s 10 -U $USER load

cd ..

python3 bench.py guo543 ./queries

