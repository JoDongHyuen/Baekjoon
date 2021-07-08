# --------------------------------------
# 가장 긴 증가하는 부분 수열 5
# --------------------------------------

from collections import deque
import sys
import bisect

A = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

LIS = deque()
result = [arr[0]]
result_idx = [0]
parent = [x for x in range(A)]

for i in range(1, A):
    if result[-1] < arr[i]:
        parent[i] = result_idx[-1]
        result.append(arr[i])
        result_idx.append(i)
    else:
        index = bisect.bisect_left(result, arr[i])
        result[index] = arr[i]
        result_idx[index] = i
        if index != 0:
            parent[i] = result_idx[index - 1]

index = result_idx[-1]
LIS.appendleft(arr[index])
while index != parent[index]:
    index = parent[index]
    LIS.appendleft(arr[index])

print(len(result_idx))
print(*LIS)