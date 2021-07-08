# --------------------------------------
# IOIOI
# --------------------------------------

from collections import deque
import collections
import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
txt = str(sys.stdin.readline().strip())
queue = deque()
condition = 2 * N + 1
count = 0

for char in txt:

    if not queue and char == 'I':
        queue.append(char)

    elif queue:

        if char == 'I':
            if queue[-1] == 'O':
                queue.append(char)
            else:
                queue = deque()
                queue.append(char)

        elif char == 'O':
            if queue[-1] == 'I':
                queue.append(char)
            else:
                queue = deque()

    if len(queue) == condition:
        count += 1
        queue.popleft()
        queue.popleft()

print(count)