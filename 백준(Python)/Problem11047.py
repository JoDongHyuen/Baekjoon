# --------------------------------------
# 동전 0
# --------------------------------------

from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())

coins = deque()

for _ in range(N):
    input = int(sys.stdin.readline().strip())
    coins.appendleft(input)

result = 0
for coin in coins:
    result = result + M // coin
    M %= coin

print(result)

