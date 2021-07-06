# --------------------------------------
# 좌표 압축
# --------------------------------------

import sys
import bisect

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

sorted_arr = sorted(list(set(arr)))

for i in range(N):
    index = bisect.bisect_left(sorted_arr, arr[i])
    arr[i] = index

print(*arr)
