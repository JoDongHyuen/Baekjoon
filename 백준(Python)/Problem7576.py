# --------------------------------------
# 토마토
# --------------------------------------

from collections import deque
import sys

col, row = map(int, sys.stdin.readline().split())

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

box = []
queue = deque()
result = 0

def printResult():
    for i in range(row):
        for j in range(col):
            if box[i][j] == 0:
                print(-1)
                return
    print(result)


for _ in range(row):
    box.append(list(map(int, sys.stdin.readline().split())))

for i in range(row):
    for j in range(col):
        if box[i][j] == 1:
            queue.append((i, j, 0))

while queue:
    row_idx, col_idx, day = queue.popleft()

    for i in range(4):
        nx = row_idx + dx[i]
        ny = col_idx + dy[i]
        if nx < 0 or ny < 0 or nx >= row or ny >= col : continue
        if box[nx][ny] == -1 or box[nx][ny] == 1 : continue
        box[nx][ny] = 1
        queue.append((nx, ny, day + 1))
        if (day + 1) > result:
            result = day + 1

printResult()