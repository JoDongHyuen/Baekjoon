# --------------------------------------
# 주유소
# -------------------------------------- 

import sys

N = int(sys.stdin.readline())

distance = [0] + list(map(int, sys.stdin.readline().split()))
price = list(map(int, sys.stdin.readline().split()))

result = 0
now = 0
dist = 0

for i in range(1, len(price)):
    dist += distance[i]

    if price[now] > price[i]:
        result += dist * price[now]
        now = i
        dist = 0

result += dist * price[now]

print(result)