# --------------------------------------
# 아기 상어
# -------------------------------------- 

from collections import deque
import sys

dx = [0, 1, -1, 0]
dy = [1, 0, 0, -1]

sea = []
total_move = 0
now_size = 2
eat_count = 0


def BFS(now_row, now_col, move):

    global eat_count, total_move, now_size

    visited = [[False for __ in range(N)] for _ in range(N)]
    queue = deque()
    queue.append((now_row, now_col, move))

    while queue:
        row, col, move_count = queue.popleft()
        visited[row][col] = True

        for i in range(3,- 1, -1):
            nrow =  row + dy[i]
            ncol = col + dx[i]
            
            if nrow < 0 or nrow >= N: continue
            if ncol < 0 or ncol >= N: continue
            if visited[nrow][ncol] : continue
            if sea[nrow][ncol] == 0 or sea[nrow][ncol] == now_size:
                queue.append((nrow, ncol, move_count + 1))
                continue
            # 아기상어가 먹을 수 있는 먹이 발견
            if sea[nrow][ncol] < now_size:
                move_count += 1
                eat_count += 1
                total_move += move_count
                
                # 아기상어가 우선 순위에 맞게 먹이를 찾아가게 하는 코드
                while queue:
                    chk_row, chk_col, move_chk = queue.popleft()
                    visited[chk_row][chk_col] = True

                    if move_chk < move_count:
                        for j in range(3,- 1, -1):
                            mrow = chk_row + dy[j]
                            mcol = chk_col + dx[j]
                            if mrow < 0 or mrow >= N: continue
                            if mcol < 0 or mcol >= N: continue
                            if visited[mrow][mcol] : continue
                            if sea[mrow][mcol] == 0 : continue
                            if sea[mrow][mcol] < now_size:
                                queue.append((mrow, mcol, move_chk + 1))

                    elif move_chk == move_count and sea[chk_row][chk_col] != 0 and sea[chk_row][chk_col] < now_size:
                        if chk_row < nrow:
                            nrow = chk_row
                            ncol = chk_col
                        elif chk_row == nrow and chk_col < ncol:
                            nrow = chk_row
                            ncol = chk_col                            
                
                # 아기상어 성장
                if eat_count == now_size:
                    now_size += 1
                    eat_count = 0
                
                sea[nrow][ncol] = 0
                return nrow, ncol

    return -1, -1


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