# --------------------------------------
# 타임머신
# --------------------------------------

import sys
from math import isinf

N, M = map(int, sys.stdin.readline().split())

result = [float('inf') for _ in range(N + 1)]
result[1] = 0

edges = []
for _ in range(M):
    root = list(map(int, sys.stdin.readline().split()))
    edges.append(root)

# 벨만 포드 알고리즘
for _ in range(1, N):
    for edge in edges:
        u = edge[0]
        v = edge[1]
        w = edge[2]
        if (result[v] > result[u] + w):
            result[v] = result[u] + w


# 사이클의 합이 음수인 부분이 있는지 확인
check = 1
for edge in edges:
    u = edge[0]
    v = edge[1]
    w = edge[2]
    if (result[v] > result[u] + w):
        check = 0

# 출력
if check == 0:
    print(-1)
else:
    for num in range(2, N + 1):
        if isinf(result[num]): print(-1)
        else : print(result[num])