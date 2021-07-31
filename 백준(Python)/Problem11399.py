# --------------------------------------
# ATM
# -------------------------------------- 

import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

result = 0
arr = sorted(arr)
length = len(arr)

for i in arr:
    result += i * length
    length -= 1

print(result)