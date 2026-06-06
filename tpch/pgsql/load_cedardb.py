#!/usr/bin/env python3

import argparse
import os
import subprocess
import sys

TABLES = ['part', 'supplier', 'partsupp', 'customer', 'orders', 'lineitem', 'nation', 'region']

DATA_DIR = os.path.join(os.path.dirname(__file__), 'tpch-pgsql', 'data', 'load')
PREP_QUERY_DIR = os.path.join(os.path.dirname(__file__), 'tpch-pgsql', 'query_root', 'prep_query')


def psql_cmd(user, host, port):
    cmd = ['psql', '-U', user]
    if host:
        cmd += ['-h', host]
    if port:
        cmd += ['-p', str(port)]
    return cmd


def run(cmd, description):
    print(f'Running: {description}')
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f'FAILED: {description}')
        print(result.stderr)
        sys.exit(1)
    if result.stdout:
        print(result.stdout)


def main():
    parser = argparse.ArgumentParser(description='Load TPC-H data into CedarDB via psql')
    parser.add_argument('-U', '--user', default='postgres')
    parser.add_argument('-H', '--host', default=None)
    parser.add_argument('-p', '--port', type=int, default=None)
    args = parser.parse_args()

    base = psql_cmd(args.user, args.host, args.port)

    # Step 1: drop tables if they exist
    drop_sql = '; '.join(f'DROP TABLE IF EXISTS {t}' for t in reversed(TABLES))
    run(base + ['-c', drop_sql], 'drop existing tables')

    # Step 2: create tables
    create_tbl = os.path.join(PREP_QUERY_DIR, 'create_tbl.sql')
    run(base + ['-f', create_tbl], f'create tables ({create_tbl})')

    # Step 3: load data
    for table in TABLES:
        data_file = os.path.abspath(os.path.join(DATA_DIR, f'{table}.tbl.csv'))
        copy_sql = f"\\copy {table} FROM '{data_file}' WITH (DELIMITER '|')"
        run(base + ['-c', copy_sql], f'load {table}')

    # Step 4: create indexes
    #create_idx = os.path.join(PREP_QUERY_DIR, 'create_idx.sql')
    #run(base + ['-f', create_idx], f'create indexes ({create_idx})')

    print('Done.')


if __name__ == '__main__':
    main()
