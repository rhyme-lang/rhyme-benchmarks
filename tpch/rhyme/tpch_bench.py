import os
import subprocess
import re

import matplotlib.pyplot as plt
import numpy as np

N = 5


def bench(rhyme_exec):
    print("running rhyme generated query " + rhyme_exec)
    os.system(f"{rhyme_exec} > /dev/null 2>&1")

    res = []
    line = ""
    for _ in range(N):
        result = subprocess.run([rhyme_exec], capture_output=True, text=True)
        time = re.findall("[0-9]+", result.stderr)
        print(time)
        res.append(int(time[1]) / 1000)
        line += time[1] + " "

    avg = sum(res) / N
    median = np.median(res)
    line += str(median) + " " + str(avg) + "\n"
    print(res)
    return median, line


rhyme = []
medians = []
text = ""

cedar_medians = {}
cedar_text = ""

for i in range(1, 23):
    rhyme_exec = "./out/q" + str(i)
    median, line = bench(rhyme_exec)
    medians.append(median)
    text += line

    cedar_exec = "./out/q" + str(i) + "_cedar"
    if os.path.isfile(cedar_exec):
        cedar_median, cedar_line = bench(cedar_exec)
        cedar_medians[i] = cedar_median
        cedar_text += f"q{i}_cedar " + cedar_line

for i in range(22):
  print(f"(Q{i + 1}, {int(medians[i])})")

for i in range(22):
  print(str(int(medians[i])) + "&")

print(text)
with open("out.txt", "w") as f:
    f.write(text)

if cedar_medians:
    print("\n--- CedarDB variants ---")
    for i in sorted(cedar_medians):
        print(f"(Q{i}_cedar, {int(cedar_medians[i])})")
    for i in sorted(cedar_medians):
        print(str(int(cedar_medians[i])) + "&")
    print(cedar_text)
    with open("out_cedar.txt", "w") as f:
        f.write(cedar_text)


# Query labels
#queries = np.arange(1, 23)  # 1 to 22

# Bar width and positions
#bar_width = 0.35
#x = np.arange(len(queries))

# Plot
#plt.figure(figsize=(12, 6))
#plt.bar(x - bar_width/2, rhyme, bar_width, label='Rhyme')
#plt.bar(x + bar_width/2, flare, bar_width, label='Flare')

# Formatting
#plt.xlabel('TPC-H Query')
#plt.ylabel('Runtime (milliseconds)')
#plt.title('Rhyme vs Flare Runtime on TPC-H Queries')
#plt.xticks(x, [f'Q{i}' for i in queries], rotation=45)
#plt.legend()
#plt.tight_layout()
#plt.grid(axis='y', linestyle='--', alpha=0.7)

#plt.savefig('plot.jpeg', format='jpeg')
