# --------------------------------------
# DSLR
# --------------------------------------

from collections import deque
import sys

T = int(sys.stdin.readline())

for _ in range(T):
    queue = deque()
    visited = [False] * 10000

    A, B = map(int, sys.stdin.readline().split())

    queue.append((A, ''))

    while queue:
        num, cmd = queue.popleft()

        if visited[num]:
            continue

        if num == B:
            break

        queue.append((num * 2 % 10000, cmd + 'D'))
        
        temp = num - 1
        if temp < 0:
            temp = 9999
        queue.append((temp, cmd + 'S'))

        temp = num * 10 % 10000 + num // 1000
        queue.append((temp, cmd + 'L'))

        temp = num // 10 + num % 10 * 1000
        queue.append((temp, cmd + 'R'))

        visited[num] = True

    print(cmd)