# --------------------------------------
# 두 용액
# --------------------------------------

import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()

start = 0
end = len(arr) - 1
result = False
x = 0
y = 0

while start < end:
    mix = arr[start] + arr[end]

    if not result:
        result = abs(mix)
        x = start
        y = end
    elif result > abs(mix):
        result = abs(mix)
        x = start
        y = end    

    if mix == 0 :
        x = start
        y = end
        break
    elif mix > 0:
        end -= 1
    elif mix < 0:
        start += 1


print(arr[x], arr[y])
