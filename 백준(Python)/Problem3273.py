# --------------------------------------
# 두 수의 합
# --------------------------------------

import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
x = int(sys.stdin.readline())

arr.sort()


start = 0
end = len(arr) - 1
count = 0

while start < end:
    temp = arr[start] + arr[end]
    
    if temp == x:
        count += 1
        start += 1
    elif temp > x:
        end -= 1
    elif temp < x:
        start += 1

print(count)
