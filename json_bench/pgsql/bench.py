#!/usr/bin/env python3

import subprocess
import sys
import statistics
from pathlib import Path

def run_query(query_file, username, measure=False):
    """Run a single query and return execution time in milliseconds"""

    if measure:
        # Use \timing to get execution time
        # Disable parallel execution for consistent benchmarking
        result = subprocess.run(
            ['psql', '-U', username, '-d', 'json_bench',
             '-c', 'SET max_parallel_workers_per_gather = 0;',
             '-c', '\\timing',
             '-f', str(query_file)],
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True
        )

        # Parse all timing entries and sum them (for queries with multiple statements like Q15)
        total_time_ms = 0.0
        time_count = 0

        for line in result.stdout.split('\n'):
            if 'Time:' in line:
                # Extract the number before "ms"
                time_str = line.split('Time:')[1].strip().split()[0]
                time_ms = float(time_str)
                total_time_ms += time_ms
                time_count += 1

        if time_count > 0:
            return total_time_ms

        return None
    else:
        # Warmup run - also disable parallel execution
        subprocess.run(
            ['psql', '-U', username, '-d', 'json_bench',
             '-c', 'SET max_parallel_workers_per_gather = 0;',
             '-f', str(query_file)],
            capture_output=True
        )
        return None

def benchmark_query(query_file, username):
    """Run warmup + 5 timed runs, return results"""
    # Warmup run (throw away)
    run_query(query_file, username, measure=False)

    # 5 benchmark runs with server-side timing
    times = []
    for _ in range(5):
        elapsed = run_query(query_file, username, measure=True)
        if elapsed is None:
            raise Exception("Could not parse execution time")
        times.append(elapsed)
    
    median = statistics.median(times)
    average = statistics.mean(times)
    
    return times, median, average

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 benchmark.py <username> <path_to_sql_files>")
        print("Example: python3 benchmark.py myuser ./queries")
        sys.exit(1)

    username = sys.argv[1]
    sql_path = Path(sys.argv[2])
    
    if not sql_path.exists():
        print(f"Error: Path '{sql_path}' does not exist")
        sys.exit(1)
    
    # Get all SQL files in order 1-22
    if sql_path.is_file():
        sql_files = [sql_path]
    else:
        # Look for query files numbered 1.sql - 22.sql
        sql_files = []
        for i in range(1, 6):
            query_file = sql_path / f"q{i}.sql"
            if query_file.exists():
                sql_files.append(query_file)
    
    if not sql_files:
        print(f"Error: No .sql files found in '{sql_path}'")
        sys.exit(1)
    
    # Run benchmarks
    results_file = "benchmark_results.txt"
    
    print("\nNote: Parallel query execution is DISABLED for consistent benchmarking")
    print("(max_parallel_workers_per_gather = 0)\n")
    
    with open(results_file, 'w') as f:
        for query_file in sql_files:
            print(f"Benchmarking {query_file.name}...")
            
            try:
                times, median, average = benchmark_query(query_file, username)
                
                # Write: time1 time2 time3 time4 time5 median average
                line = ' '.join([f"{t:.2f}" for t in times])
                line += f" {median:.2f} {average:.2f}\n"
                f.write(line)
                
                times_str = ', '.join([f"{t:.2f}ms" for t in times])
                print(f"  Times: [{times_str}]")
                print(f"  Median: {median:.2f}ms, Mean: {average:.2f}ms")
                
            except Exception as e:
                print(f"  Error: {e}")
                f.write(f"ERROR ERROR ERROR ERROR ERROR ERROR ERROR\n")
    
    print(f"\nResults written to: {results_file}")

if __name__ == "__main__":
    main()
