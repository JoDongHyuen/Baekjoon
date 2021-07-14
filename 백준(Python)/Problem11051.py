# --------------------------------------
# 이항 계수 2
# -------------------------------------- 

import sys

N, K = map(int, sys.stdin.readline().split())

dp = [[1 for col in range(N + 1)] for row in range(N + 1)]

for i in range(2, N + 1):
    for j in range(1, i):
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007

print(dp[N][K])
