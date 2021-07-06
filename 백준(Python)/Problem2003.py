# --------------------------------------
# 수들의 합 2
# --------------------------------------

import sys

N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

start = -1
end = -1
sum = 0
count = 0

while start < N:
    if end < N- 1 and sum < M:
        end += 1
        sum += arr[end]
    elif start < N - 1 and sum > M:
        start += 1
        sum -= arr[start]
    elif sum == M:
        count += 1
        start += 1
        sum -= arr[start]
    else:
        break

print(count)
