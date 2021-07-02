# -------------------------------------
# 적록색약
# -------------------------------------

from collections import deque
import sys
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def BFS_1(row, col):
    queue = deque()

    queue.append((row, col, grid[row][col]))
    visited_1[row][col] = 1

    while queue:
        now_row, now_col, color = queue.popleft()

        for i in range(4):
            move_row = now_row + dx[i]
            move_col = now_col + dy[i]

            if(move_row < 0 or move_row >= N): continue
            if(move_col < 0 or move_col >= N): continue
            if(visited_1[move_row][move_col] == 1): continue
            if(grid[move_row][move_col] != color): continue
            queue.append((move_row, move_col, grid[move_row][move_col]))
            visited_1[move_row][move_col] = 1



def BFS_2(row, col):
    queue = deque()

    queue.append((row, col, grid[row][col]))
    visited_2[row][col] = 1

    while queue:
        now_row, now_col, color = queue.popleft()

        for i in range(4):
            move_row = now_row + dx[i]
            move_col = now_col + dy[i]

            if(move_row < 0 or move_row >= N): continue
            if(move_col < 0 or move_col >= N): continue
            if(visited_2[move_row][move_col] == 1): continue
            if(color == 'B' and color != grid[move_row][move_col]): continue
            if((color == 'R' or color == 'G') and grid[move_row][move_col] == 'B'): continue
            queue.append((move_row, move_col, grid[move_row][move_col]))
            visited_2[move_row][move_col] = 1

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    grid = []
    for _ in range(N):
        grid.append(str(sys.stdin.readline().strip()))
    
    result_1 = 0
    result_2 = 0

    visited_1 = [[0 for _ in range(N)] for __ in range(N)]
    visited_2 = [[0 for _ in range(N)] for __ in range(N)]

    for row in range(N):
        for col in range(N):
            # 적록색약 아닌 사람
            if visited_1[row][col] == 0:
                BFS_1(row, col)
                result_1 += 1

            # 적록색약인 사람
            if visited_2[row][col] == 0:
                BFS_2(row, col)
                result_2 += 1
    
    print("{} {}".format(result_1, result_2))