# --------------------------------------
# 테트로미노
# --------------------------------------

from collections import deque
import sys

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, sys.stdin.readline().split())
visited = [[False for _ in range(M)] for __ in range(N)]
poly = []
result = 0

def DFS(row, col, sum, count):

    global result

    if count == 4:
        result = max(result, sum)
    else:
        for i in range(4):
            nx = row + dx[i]
            ny = col + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= M: continue
            if visited[nx][ny]: continue
            visited[nx][ny] = True
            DFS(nx, ny, sum + poly[nx][ny], count + 1)
            visited[nx][ny] = False
    
for _ in range(N):
    poly.append(list(map(int, sys.stdin.readline().split())))

# 큐에 넣을 때, visited를 설정 안 해주는 방법 사용하면
# DFS를 활용해 ㅗ, ㅏ ㅜ, ㅓ 모양 빼고 전부 체크 가능함
for i in range(N):
    for j in range(M):
        visited[i][j] = True
        DFS(i, j, poly[i][j], 1)
        visited[i][j] = False

for i in range(N):
    for j in range(M):

        # ㅏ 모양 체크
        if i >= 1 and i < (N - 1) and j < (M - 1):
            sum = poly[i][j] + poly[i + 1][j] + poly[i - 1][j] + poly[i][j + 1]
            result = max(result, sum)

        # ㅓ 모양 체크
        if i >= 1 and i < (N - 1) and j >= 1:
            sum = poly[i][j] + poly[i + 1][j] + poly[i - 1][j] + poly[i][j - 1]
            result = max(result, sum)

        # ㅜ 모양 체크
        if i < (N - 1) and j >= 1 and j < (M - 1):
            sum = poly[i][j] + poly[i + 1][j] + poly[i][j - 1] + poly[i][j + 1]
            result = max(result, sum)

        # ㅗ 모양 체크
        if i >= 1 and j >= 1 and j < (M - 1):
            sum = poly[i][j] + poly[i - 1][j] + poly[i][j - 1] + poly[i][j + 1]
            result = max(result, sum)

print(result)