# --------------------------------------
# 단지번호붙이기
# --------------------------------------

from collections import deque
import sys
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def BFS(row, col):

    count = 0

    queue = deque()
    queue.append((row, col))
    visited[row][col] = True
    count += 1

    while queue:
        idx_row, idx_col = queue.popleft()

        for i in range(4):
            moved_row = idx_row + dx[i]
            moved_col = idx_col + dy[i]
            if moved_row < 0 or moved_row >= map_size: continue
            if moved_col < 0 or moved_col >= map_size: continue
            if apt[moved_row][moved_col] == '0' or visited[moved_row][moved_col] == True: continue
            queue.append((moved_row, moved_col))
            visited[moved_row][moved_col] = True
            count += 1
    
    result.append(count)


if __name__=="__main__":
    map_size = int(sys.stdin.readline())
    apt = []
    result = []

    for _ in range(map_size):
        apt.append(sys.stdin.readline().strip())

    visited = [[False for _ in range(map_size)] for _ in range(map_size)]

    for row in range(map_size):
        for col in range(map_size):
            if apt[row][col] == '1' and visited[row][col] == False:
                BFS(row, col)

    
    result.sort()
    print(len(result))
    for i in result:
        print(i)