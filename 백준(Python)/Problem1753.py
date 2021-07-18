# --------------------------------------
# 최단경로
# -------------------------------------- 

import heapq
import sys

V, E = map(int, sys.stdin.readline().split())
start = int(sys.stdin.readline())

Edge = [[] for _ in range(V + 1)]
shortest = [sys.maxsize for _ in range(V + 1)]
visited = [False for _ in range(V + 1)]

for _ in range(E):
    u ,v, w = map(int, sys.stdin.readline().split())
    Edge[u].append((v, w))


queue = []
heapq.heappush(queue, (0, start))
shortest[start] = 0

# 다익스트라
while queue:
    distance, idx = heapq.heappop(queue)

    if visited[idx] == True:
        continue
    visited[idx] = True

    for dest, weight in Edge[idx]:
        if distance + weight < shortest[dest]:
            shortest[dest] = distance + weight
            heapq.heappush(queue, (shortest[dest], dest))

# 출력
for i in range(1, V + 1):
    if shortest[i] == sys.maxsize:
        print("INF")
    else:
        print(shortest[i])