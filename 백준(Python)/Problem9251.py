# -------------------------------------
# LCS
# -------------------------------------

import sys

str1 = sys.stdin.readline().strip()
str2 = sys.stdin.readline().strip()

DP = [[0 for col in range(len(str2) + 1)] for row in range(len(str1) + 1)]

for row in range(1, len(str1) + 1):
    for col in range(1, len(str2) + 1):
        if str1[row - 1] == str2[col - 1]:
            DP[row][col] = DP[row - 1][col - 1] + 1
        else:
            DP[row][col] = max(DP[row - 1][col], DP[row][col - 1])

print(DP[len(str1)][len(str2)])