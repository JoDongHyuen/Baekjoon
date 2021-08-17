# --------------------------------------
# 경로 찾기
# -------------------------------------- 

from collections import deque
import sys

N = int(sys.stdin.readline())

IG = []
result = [[0 for _ in range(N)] for __ in range(N)]


def BFS(start):
    queue = deque()
    queue.append(start)
    visited = [False] * N

    while queue:
        now = queue.popleft()
        
        if visited[now]: continue
        visited[now] = True

        for i in range(N):
            if IG[now][i] == 0: continue
            queue.append(i)
            result[start][i] = 1

for _ in range(N):
    IG.append(list(map(int, sys.stdin.readline().split())))


for i in range(N):
    BFS(i)

for row in result:
    print(*row)
