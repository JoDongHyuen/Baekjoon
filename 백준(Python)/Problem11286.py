# --------------------------------------
# 절댓값 힙
# -------------------------------------- 

import heapq
import sys

N = int(sys.stdin.readline())
arr = []

for _ in range(N):
    num = int(sys.stdin.readline())

    if num == 0:
        if arr:
            print(heapq.heappop(arr)[1])
        else:
            print(0)
    else:
        heapq.heappush(arr, (abs(num), num))