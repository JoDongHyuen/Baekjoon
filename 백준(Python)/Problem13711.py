# --------------------------------------
# LCS 4
# -------------------------------------- 

import sys
import bisect

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
temp = [0 for _ in range(N)]
B = list(map(int, sys.stdin.readline().split()))
C = []

for i in range(N):
    temp[A[i] - 1] = i

for i in range(N):
    C.append(temp[B[i] - 1])

result = []
result.append(C[0])

for i in range(1, N):
    if result[-1] < C[i]:
        result.append(C[i])
    else:
        index = bisect.bisect_left(result, C[i])
        result[index] = C[i]

print(len(result))

