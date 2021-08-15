# --------------------------------------
# 아기 상어
# -------------------------------------- 

from collections import deque
import heapq
import sys

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

sea = []
total_move = 0
now_size = 2
eat_count = 0


def BFS(now_row, now_col, move):

    global eat_count, total_move, now_size

    visited = [[False for __ in range(N)] for _ in range(N)]
    queue = []
    eat = []
    queue = deque()
    queue.append((move, now_row, now_col))

    while queue:
        move_count, row, col = queue.popleft()
        visited[row][col] = True

        for i in range(4):
            nrow =  row + dy[i]
            ncol = col + dx[i]
            
            if nrow < 0 or nrow >= N: continue
            if ncol < 0 or ncol >= N: continue
            if visited[nrow][ncol] : continue
            if sea[nrow][ncol] == 0 or sea[nrow][ncol] == now_size:
                queue.append((move_count + 1, nrow, ncol))
                continue
            if sea[nrow][ncol] < now_size:
                heapq.heappush(eat, (move_count + 1, nrow, ncol))               
    
    if eat:
        move, row, col = eat[0]
        total_move += move
        sea[row][col] = 0

        eat_count += 1
        if eat_count == now_size:
            now_size += 1
            eat_count = 0
        
        return row, col

    else:   return -1, -1


N = int(sys.stdin.readline())
for i in range(N):
    sea.append(list(map(int, sys.stdin.readline().split())))
    if 9 in sea[i]:
        now_row = i
        now_col = sea[i].index(9)

sea[now_row][now_col] = 0

while True:
    now_row, now_col = BFS(now_row, now_col, 0)
    if now_row == -1:
        break

print(total_move)