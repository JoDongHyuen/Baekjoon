# --------------------------------------
# 줄세우기
# --------------------------------------

import sys
import bisect

N = int(sys.stdin.readline())

LIS = []

for _ in range(N):
    num = int(sys.stdin.readline())

    index = bisect.bisect_left(LIS, num)

    if not LIS:
        LIS.append(num)
        continue

    if LIS[-1] < num:
        LIS.append(num)
    else:
        LIS[index] = num

print(N - len(LIS))
print(LIS)