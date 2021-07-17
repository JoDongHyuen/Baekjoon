# --------------------------------------
# 카잉 달력
# --------------------------------------

import sys
import math

T = int(sys.stdin.readline())

for _ in range(T):
    M, N, x, y = map(int, sys.stdin.readline().split())

    if M == N:
        if x == y:
            print(x)
        else:
            print(-1)
        continue
    else:
        M, N = N, M
        x, y = y, x

    GCD = math.gcd(M, N)
    LCM = (M // GCD) * N

    result = x
    y = y % N

    while result <= LCM:
        if result % N == y:
            break
        else:
            result += M

    if result > LCM:
        print(-1)
    else:
        print(result)

            