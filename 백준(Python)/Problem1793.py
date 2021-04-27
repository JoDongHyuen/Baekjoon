# --------------------------------------
# 타일링
# --------------------------------------

from sys import stdin

DP = [0 for x in range(251)]

DP[0] = 1
DP[1] = 1
DP[2] = 3

for i in range(3, 251):
    DP[i] = DP[i - 1] + 2 * DP[i - 2]

for n in map(int, stdin.read().split()):
    print(DP[n])