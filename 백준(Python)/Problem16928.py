# --------------------------------------
# 뱀과 사다리 게임
# -------------------------------------- 

from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())

visited = [False] * 101
ladder = {}
snake = {}
queue = deque()

for _ in range(N):
    x, y = map(int,sys.stdin.readline().split())
    ladder[x] = y

for _ in range(M):
    u, v = map(int,sys.stdin.readline().split())
    snake[u] = v

queue.append((1, 0))

while queue:
    start, times = queue.popleft()

    if visited[start] == True: continue
    visited[start] = True

    if start == 100: break

    for i in range(1, 7):
        if (start + i) in ladder:
            queue.append((ladder[(start + i)], times + 1))
            continue
        if (start + i) in snake:
            queue.append((snake[(start + i)], times + 1))
            continue
        queue.append((start + i, times + 1))

print(times)
