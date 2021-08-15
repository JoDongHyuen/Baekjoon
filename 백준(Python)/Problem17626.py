# --------------------------------------
# Four Squares
# -------------------------------------- 

import sys
import math

n = int(sys.stdin.readline())

dp = [0] * (n + 1)

dp[0] = 0
dp[1] = 1

for i in range(2, n + 1):
    if int(math.sqrt(i)) ** 2 == i: dp[i] = 1
    else: dp[i] = i

for i in range(2, n + 1):
    limit = math.floor(math.sqrt(i)) + 1

    for j in range(1, limit):
        dp[i] = min(dp[i], dp[j * j] + dp[i - j * j])

print(dp[n])