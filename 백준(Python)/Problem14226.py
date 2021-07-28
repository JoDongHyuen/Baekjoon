# --------------------------------------
# 이모티콘
# --------------------------------------

from collections import deque
import sys

S = int(sys.stdin.readline())
visited = [[True for _ in range(1001)] for __ in range(1001)]

queue = deque()
queue.append((1, 0, 0))

while queue:
    num, time, clip = queue.popleft()

    if visited[num][clip] == False : continue
    
    if num == S:
        break
    visited[num][clip] = False
    
    if num < S and visited[num][num] :
        queue.append((num, time + 1, num))
    if num + clip <= S and visited[num + clip][clip] :
        queue.append((num + clip, time + 1, clip))
    if num >= 1 and visited[num - 1][clip] :
        queue.append((num - 1, time + 1, clip))


print(time)