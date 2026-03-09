# rhyme-benchmarks

This repository contains scripts/code that runs the benchmarks for evaluation on diverse workloads.

For the TPC-H benchmark, we used code from the following repositories and made changes to stick to our evaluation configurations.

- [tpch-pgsql](https://github.com/Data-Science-Platform/tpch-pgsql)
- [tpch-spark](https://github.com/ssavvides/tpch-spark)

For JSONBench, we used the queries & commands from the official JSONBench repository: [JSONBench](https://github.com/ClickHouse/JSONBench/tree/main).

Note that the code for evaluating the performance of Flare is not included since the source code of Flare is not publicly available.

## Prerequisites

To run the benchmarks, the following tools / softwares needs to be available on the machine (relevant executables needs to be on PATH):

- PostgreSQL 18.1. (the server needs to be running with the existance of a database named tpch)
- Spark 4.1.1. The Scala toolchain is required to compile the Scala code along with Java. Note that Spark 4.1.1 runs on Java 17/21, Scala 2.13.
- DuckDB 1.4.4.
- jq 1.8.1.
- Python is required along with the venv module.
- node.js --- Rhyme is well tested with node.js 16.x, 18.x & 20.x.
- gcc and tcc is required for the compilation of the C code and the compilation time analysis.

## Get Rhyme

Rhyme is included as a submodule. Run the following command to update submodule:

```
git submodule update --init
```

## Running the Benchmarks

To run all benchmarks at once:

```
./run_all.sh <USER> <GITHUB_TOKEN>
```

Where `<USER>` is the PostgreSQL username and `<GITHUB_TOKEN>` is a GitHub personal access token.

Alternatively, each benchmark suite can be run separately:

```
./tpch.sh <USER>
./json_bench.sh <USER>
./additional.sh <GITHUB_TOKEN>
```

The sections below describe step-by-step execution for each benchmark suite.

## TPC-H

First, generate the data for TPC-H. Execute the command in ./tpch:

```
# execute inside ./tpch
./get_data.sh
```

### PostgreSQL

Run the bash script under ./tpch/pgsql. The username for postgres is required. A database with the name "tpch" is expected to exist.

```
# execute inside ./tpch/pgsql
./tpch_pgsql.sh <username>
```

### Spark

Run the following commands under ./tpch/spark/tpch-spark.

```
# execute inside ./tpch/spark/tpch-spark
sbt package
./run.sh
```

The script writes all results into times.txt in the same directory.

### Rhyme

Run the bash script under ./tpch/rhyme.

```
# execute inside ./tpch/rhyme
./tpch_rhyme.sh
```

## JSONBench

First, generate the data for JSONBench. Execute the command in ./json_bench:

```
# execute inside ./json_bench
./get_bluesky.sh
```

### PostgreSQL

Run the bash script under ./json_bench/pgsql. The username for postgres is required. A database with the name "json_bench" is expected to exist.

```
# execute inside ./json_bench/pgsql
./json_bench_pgsql.sh <username>
```

### DuckDB

Run the bash script under ./json_bench/duckdb.
```
# execute inside ./json_bench/duckdb
./json_bench_duckdb.sh
```

### Rhyme

Run the bash script under ./json_bench/rhyme.

```
# execute inside ./json_bench/rhyme
./json_bench_rhyme.sh
```

## Additional Queries

First, generate the full data and sliced data files. Please note that get_commits fetches from Github's rest API and uses a Github access token. Execute the command in ./additional:

```
./get_commits.sh <Github access token>
./gen_slices.sh
```

### JQ

Run the Python script under ./additional/jq.

```
# execute inside ./additional/jq
python3 bench.py
```

### Rhyme

Run the bash script under ./additional/rhyme.

```
# execute inside ./additional/rhyme
./bench.sh
```

### End-to-End execution time analysis

Run the Python script under ./additional/rhyme.

```
# execute inside ./additional/rhyme
python3 compile_bench.py
```
