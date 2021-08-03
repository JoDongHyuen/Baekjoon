# --------------------------------------
# 구간 합 구하기 4
# --------------------------------------

import sys

N, M = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

dp = [0, arr[0]]

for i in range(1, len(arr)):
    dp.append(arr[i] + dp[i])


for _ in range(M):
    i, j = map(int, sys.stdin.readline().split())
    print(dp[j] - dp[i - 1])
