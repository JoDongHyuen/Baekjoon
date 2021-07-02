# --------------------------------------
# 골드바흐의 추측
# --------------------------------------

import sys
import math

check = [True for _ in range(1000001)]
check[0] = False
check[1] = False
end = math.floor(math.sqrt(1000000))
for i in range(2, end + 1):
    if check[i]:
        sum = i + i
        while sum <= 1000000:
            check[sum] = False
            sum += i

while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break
    else:
        for i in range(3, 100001, 2):
            if check[i] == True and check[n - i] == True:
                print("{} = {} + {}".format(n, i, n - i))
                break


