# --------------------------------------
# 행렬 곱셈
# --------------------------------------

import sys

N, M = map(int, sys.stdin.readline().split())
M1 = []
for _ in range(N):
    M1.append(list(map(int, sys.stdin.readline().split())))


M, K = map(int, sys.stdin.readline().split())
M2 = []
for _ in range(M):
    M2.append(list(map(int, sys.stdin.readline().split())))

result = [[0 for _ in range(K)] for __ in range(N)]

for i in range(N):
    for j in range(K):
        for k in range(M):
            result[i][j] += M1[i][k] * M2[k][j]

for i in range(len(result)):
    print(*result[i])