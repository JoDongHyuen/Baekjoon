# --------------------------------------
# 카드 놓기
# --------------------------------------

from collections import deque
import sys

N = int(sys.stdin.readline())
card = deque(map(int, sys.stdin.readline().split()))
result = deque()

for i in range(1, N + 1):
    skill = card.pop()

    if skill == 1:
        result.appendleft(i)
    elif skill == 2:
        result.insert(1, i)
    else:
        result.append(i)

print(*result)