# --------------------------------------
# 토마토
# --------------------------------------

from collections import deque
import sys
dx = [1, 0, 0, -1, 0, 0]
dy = [0, 1, 0, 0, -1, 0]
dz = [0, 0, 1, 0, 0, -1]

queue = deque()
result = 0

col, row, floor = map(int, sys.stdin.readline().split())

# box = [[] * floor]
box = []

def printResult():
    for z in range(floor):
        for x in range(row):
            for y in range(col):
                if box[z][x][y] == 0:
                    print(-1)
                    return
    
    print(result)

for z in range(floor):
    box.append([])
    for _ in range(row):
        box[z].append(list(map(int, sys.stdin.readline().split())))


for z in range(floor):
    for x in range(row):
        for y in range(col):
            if box[z][x][y] == 1:
                queue.append((z, x, y, 0))

while queue:
    z_idx, x_idx, y_idx, day = queue.popleft()

    for i in range(6):
        nx = x_idx + dx[i]
        ny = y_idx + dy[i]
        nz = z_idx + dz[i]

        if nx < 0 or ny < 0 or nz < 0 or nx >= row or ny >= col or nz >= floor : continue
        if box[nz][nx][ny] == 1 or box[nz][nx][ny] == -1 : continue
        
        box[nz][nx][ny] = 1
        queue.append((nz, nx, ny, day + 1))
        if (day + 1) > result:
            result = day + 1

printResult()