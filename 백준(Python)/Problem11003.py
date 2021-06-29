# --------------------------------------
# 최솟값 찾기
# --------------------------------------

from collections import deque
import sys

N, L = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
queue = deque()

for i in range(N):

    while queue and queue[-1][1] >= arr[i]:
        queue.pop()
    
    queue.append((i, arr[i]))

    while queue[0][0] < (i - L + 1):
        queue.popleft()

    print(queue[0][1], end=" ")