import subprocess
import re
import numpy as np

N = 5

def get_compilation_time(cmd):
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    output = result.stdout + result.stderr
    match = re.search(r"Compilation:\s*([\d.]+)", output)
    if match:
        return float(match.group(1))
    raise ValueError(f"No 'Compilation: ' found in output of: {cmd}\n--- stdout ---\n{result.stdout}\n--- stderr ---\n{result.stderr}")

def benchmark(label, cmd):
    print(f"\n{label}")
    times = []
    for i in range(N):
        t = get_compilation_time(cmd)
        print(f"  run {i+1}: {t} ms")
        times.append(t)
    median = float(np.median(times))
    print(f"  median: {median} ms")
    return median

commands = [
    ("node rhyme-bench-sliced 0",  "node rhyme-bench-sliced 0"),
    ("node rhyme-bench-c 1",       "node rhyme-bench-c 1"),
    ("node rhyme-bench-c 1 tcc",   "node rhyme-bench-c 1 tcc"),
]

results = []
for label, cmd in commands:
    m = benchmark(label, cmd)
    results.append((label, m))

print("\n=== Summary ===")
for label, m in results:
    print(f"  {label}: {m} ms")

compilation_gcc = results[1][1]
compilation_tcc = results[2][1]

import os

def run_slice_bench(label, compilation):
    print(f"\n=== Slice bench ({label}, compilation={compilation} ms) ===")
    os.system(f"node rhyme-bench-sliced-c {label}")
    medians = []
    text = ""

    for i in range(1, 11):
        rhyme_exec = f"./out/q1_{i}000"

        print(f"running rhyme query {rhyme_exec}")
        os.system(f"{rhyme_exec} > /dev/null 2>&1")

        res = []
        for _ in range(N):
            result = subprocess.run([rhyme_exec], capture_output=True, text=True)
            time = re.findall("[0-9]+", result.stderr)
            print(time)
            res.append(int(time[2]) / 1000 + compilation)
            text += time[2] + " "

        avg = sum(res) / N
        median = np.median(res)
        medians.append(median)
        text += str(median) + " " + str(avg) + "\n"
        print(res)

    for i in range(10):
        print(f"({i+1}00000, {int(medians[i])})")

    for i in range(10):
        print(str(int(medians[i])) + "&")

    print(text)
    out_file = f"out_{label}.txt"
    with open(out_file, "w") as f:
        f.write(text)

run_slice_bench("gcc", compilation_gcc)
run_slice_bench("tcc", compilation_tcc)

def run_slice_bench_js():
    print(f"\n=== Slice bench (js) ===")
    medians = []
    text = ""

    for i in range(1, 2):
        n = i * 1000
        cmd = f"node rhyme-bench-sliced {n}"

        print(f"running rhyme query {cmd}")

        res = []
        for _ in range(N):
            result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
            output = result.stdout + result.stderr
            match = re.search(r"median:\s*([\d.]+)", output)
            t = float(match.group(1)) + results[0][1]
            print(t)
            res.append(t)
            text += str(t) + " "

        avg = sum(res) / N
        median = np.median(res)
        medians.append(median)
        text += str(median) + " " + str(avg) + "\n"
        print(res)

    for i in range(10):
        print(f"({i+1}00000, {int(medians[i])})")

    for i in range(10):
        print(str(int(medians[i])) + "&")

    print(text)
    with open("out_js.txt", "w") as f:
        f.write(text)

run_slice_bench_js()
