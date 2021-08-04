# --------------------------------------
# 연결 요소의 개수
# -------------------------------------- 

from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())

edge = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

result = 0

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    edge[u].append(v)
    edge[v].append(u)

for i in range(1, N + 1):
    if visited[i] == False:
        result += 1
        queue = deque()
        queue.append(i)
        

        while queue:
            u = queue.popleft()
            
            if visited[u]: continue
            visited[u] = True

            for v in edge[u]:
                queue.append(v)

print(result)