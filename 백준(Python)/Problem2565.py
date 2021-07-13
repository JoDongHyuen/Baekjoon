# --------------------------------------
# 전깃줄
# --------------------------------------

import bisect
import sys


N = int(sys.stdin.readline())
AB = []
LIS = []

for _ in range(N):
    AB.append(tuple(map(int, sys.stdin.readline().split())))
AB.sort(key= lambda k : k[0])


LIS.append(AB[0][1])
for i in range(1, N):
    if LIS[-1] < AB[i][1]:
        LIS.append(AB[i][1])
    else:
        index = bisect.bisect_left(LIS, AB[i][1])
        LIS[index] = AB[i][1]

print(N - len(LIS))
