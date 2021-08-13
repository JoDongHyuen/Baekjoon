# --------------------------------------
# 검문
# --------------------------------------

import sys
import math

N = int(sys.stdin.readline())

arr = []
result = []


for _ in range(N):
    arr.append(int(sys.stdin.readline()))

arr.sort()

GCD = arr[1] - arr[0]

for i in range(2, len(arr)):
    value = arr[i] - arr[i - 1]
    GCD = math.gcd(GCD, value)

limit = math.floor(math.sqrt(GCD)) + 1
for i in range(2, limit):
    if GCD % i == 0:
        result.append(i)
        result.append(GCD // i)
result.append(GCD)

result = list(set(result))
result.sort()

print(*result)