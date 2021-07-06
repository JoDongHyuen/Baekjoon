# --------------------------------------
# 부분합
# --------------------------------------

import sys
import math

N, S = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

dp = [0 for _ in range(N + 1)]
dp[1] = arr[0]

for i in range(2, N + 1):
    dp[i] = dp[i - 1] + arr[i - 1]

start = 1
end = 1
result = math.inf

while end < N + 1:
    temp = dp[end] - dp[start - 1]
    length = end - start + 1

    if temp >= S:
        if result >= length:
            result = length
        start += 1
    else:
        end += 1

if (math.isinf(result)):
    print(0)
else:
    print(result)