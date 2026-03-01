#!/usr/bin/env python3

import subprocess
import statistics
import re

def run_duckdb_query(query_file):
    """Run a DuckDB query with EXPLAIN ANALYZE and return execution time in milliseconds,
    excluding the last operator (table scan)."""
    with open(query_file, 'r') as f:
        query = f.read().strip()

    # Always prepend EXPLAIN ANALYZE
    query = 'EXPLAIN ANALYZE ' + query

    # Prepare commands for DuckDB interactive mode (no .timer needed)
    commands = f"SET threads = 1;\n{query}\n"

    # Run DuckDB and pipe commands to stdin
    result = subprocess.run(
        ['duckdb', "./json_bench.db"],
        input=commands,
        capture_output=True,
        text=True
    )

    # Check for errors
    if result.returncode != 0:
        raise Exception(f"Query failed: {result.stderr}")

    # Parse per-operator timings from EXPLAIN ANALYZE output: (*.**s)
    matches = re.findall(r'\(([\d.]+)s\)', result.stdout)

    if not matches:
        raise Exception(f"Could not parse timing from output:\n{result.stdout}")

    print(matches)
    # Exclude the last timing entry (table scan) and sum the rest
    times_s = [float(t) for t in matches[:-1]]
    total_ms = sum(times_s) * 1000

    return total_ms

def benchmark_query(query_file, runs=6):
    """Run query multiple times and return median (excluding first run)"""
    times = []
    
    for i in range(runs):
        time_ms = run_duckdb_query(query_file)
        if i > 0:  # Skip first run
            times.append(time_ms)
        print(f"  Run {i+1}: {time_ms:.2f} ms" + (" (warmup, discarded)" if i == 0 else ""))
    
    return statistics.median(times)

def main():
    query_files = [f'q{i}.sql' for i in range(1, 6)]
    medians = []
    
    for query_file in query_files:
        print(f"\nBenchmarking {query_file}...")
        try:
            median_time = benchmark_query(query_file)
            medians.append(median_time)
            print(f"  Median: {median_time:.2f} ms")
        except FileNotFoundError:
            print(f"  ERROR: {query_file} not found, skipping")
            medians.append(None)
        except Exception as e:
            print(f"  ERROR: {e}")
            medians.append(None)
    
    print("\n" + "="*50)
    print("Results (median execution times in ms):")
    print("="*50)
    for i, median in enumerate(medians, 1):
        if median is not None:
            print(f"q{i}_persist.sql: {median:.2f} ms")
        else:
            print(f"q{i}_persist.sql: FAILED")
    
    # Output as array to stdout
    print("\nMedian times (ms):")
    print([round(m, 2) if m is not None else None for m in medians])

if __name__ == '__main__':
    main()
