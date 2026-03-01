import os
import subprocess
import re

import matplotlib.pyplot as plt
import numpy as np

N = 5

rhyme = []

medians = []

text = ""

for i in range(1, 11):
    rhyme_exec = f"./out/q1_{i}000"

    rhyme_out = rhyme_exec + ".out"

    print(f"running rhyme query {rhyme_exec}")
    os.system(f"{rhyme_exec} > /dev/null 2>&1")

    res = []
    for _ in range(N):
        result = subprocess.run([rhyme_exec], capture_output=True, text=True)
        time = re.findall("[0-9]+", result.stderr)
        #print(result.stderr)
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
with open("out.txt", "w") as f:
    f.write(text)


