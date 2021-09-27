# --------------------------------------
# 자동차경주대회
# --------------------------------------

from collections import deque
import sys
import math

M = int(sys.stdin.readline())
station_num = int(sys.stdin.readline())
d = deque(map(int, sys.stdin.readline().split()))
d.append(math.inf)
t = deque(map(int, sys.stdin.readline().split()))
t.appendleft(0)
t.append(0)

T = [math.inf for _ in range(station_num + 2)]
T[0] = 0
P = [-1 for _ in range(station_num + 2)]

for i in range(station_num + 1):
    j = i + 1
    D = d[i]
    while j <= station_num + 1 and D <= M:
        if T[j] > T[i] + t[j] :
            T[j] = T[i] + t[j]
            P[j] = i
        D += d[j]
        j += 1

result = deque()
st = P[station_num + 1]
while st > 0:
    result.appendleft(st)
    st = P[st]

print(T[station_num + 1])
if result:
    print(len(result))
    print(*result)
else:
    print(0)