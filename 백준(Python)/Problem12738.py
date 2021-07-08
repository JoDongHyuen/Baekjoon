# --------------------------------------
# 가장 긴 증가하는 부분 수열 3
# --------------------------------------

import sys
import bisect

A = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

result = [arr[0]]

for i in range(1, A):
    if result[-1] < arr[i]:
        result.append(arr[i])
    else:
        index = bisect.bisect_left(result, arr[i])
        result[index] = arr[i]

print(len(result))
