#!/usr/bin/env python3
import subprocess
import time
import statistics
from pathlib import Path

def run_jq_query(query_file, data_file):
    """Run a single jq query and return execution time in seconds."""
    start = time.time()
    result = subprocess.run(
        ['jq', '-c', '-n', '-f', query_file, data_file],
        capture_output=True,
        text=True
    )
    end = time.time()
    
    if result.returncode != 0:
        raise Exception(f"Query {query_file} failed: {result.stderr}")
    
    return end - start

def benchmark_query(query_file, data_file, warmup=1, runs=5):
    """Benchmark a query with warmup and multiple runs."""
    print(f"\n{'='*60}")
    print(f"Benchmarking: {query_file}")
    print(f"{'='*60}")
    
    # Warmup runs
    print(f"Warmup runs: {warmup}")
    for i in range(warmup):
        warmup_time = run_jq_query(query_file, data_file)
        print(f"  Warmup {i+1}: {warmup_time:.3f}s")
    
    # Actual benchmark runs
    print(f"\nBenchmark runs: {runs}")
    times = []
    for i in range(runs):
        exec_time = run_jq_query(query_file, data_file)
        times.append(exec_time)
        print(f"  Run {i+1}: {exec_time:.3f}s")
    
    # Calculate statistics
    median_time = statistics.median(times)
    mean_time = statistics.mean(times)
    min_time = min(times)
    max_time = max(times)
    
    print(f"\nResults:")
    print(f"  Median: {median_time:.3f}s")
    print(f"  Mean:   {mean_time:.3f}s")
    print(f"  Min:    {min_time:.3f}s")
    print(f"  Max:    {max_time:.3f}s")
    print(f"  Range:  {max_time - min_time:.3f}s")
    
    return {
        'query': query_file,
        'median': median_time,
        'mean': mean_time,
        'min': min_time,
        'max': max_time,
        'all_times': times
    }

def main():
    data_file = '../data/commits.json'
    query_files = ['q1.jq', 'q2.jq', 'q3.jq', 'q4.jq']
    
    # Check if data file exists
    if not Path(data_file).exists():
        print(f"Error: {data_file} not found!")
        return
    
    # Check which query files exist
    existing_queries = [q for q in query_files if Path(q).exists()]
    missing_queries = [q for q in query_files if not Path(q).exists()]
    
    if missing_queries:
        print(f"Warning: Missing query files: {', '.join(missing_queries)}")
    
    if not existing_queries:
        print("Error: No query files found!")
        return
    
    print(f"Found {len(existing_queries)} query file(s): {', '.join(existing_queries)}")
    print(f"Data file: {data_file}")
    
    # Run benchmarks
    results = []
    for query_file in existing_queries:
        try:
            result = benchmark_query(query_file, data_file, warmup=1, runs=5)
            results.append(result)
        except Exception as e:
            print(f"\n❌ Error running {query_file}: {e}")
            continue
    
    # Print summary
    print(f"\n{'='*60}")
    print("SUMMARY")
    print(f"{'='*60}")
    print(f"{'Query':<15} {'Median':<12} {'Mean':<12} {'Min':<12} {'Max':<12}")
    print(f"{'-'*60}")
    
    for result in results:
        print(f"{result['query']:<15} "
              f"{result['median']:>10.3f}s "
              f"{result['mean']:>10.3f}s "
              f"{result['min']:>10.3f}s "
              f"{result['max']:>10.3f}s")
    
    # Sort by median time
    if results:
        fastest = min(results, key=lambda x: x['median'])
        slowest = max(results, key=lambda x: x['median'])
        
        print(f"\n🏆 Fastest: {fastest['query']} ({fastest['median']:.3f}s)")
        print(f"🐌 Slowest: {slowest['query']} ({slowest['median']:.3f}s)")
        
        if len(results) > 1:
            speedup = slowest['median'] / fastest['median']
            print(f"⚡ Speedup: {speedup:.2f}x")

if __name__ == '__main__':
    main()
