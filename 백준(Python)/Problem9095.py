# --------------------------------------
# 1, 2, 3 더하기
# --------------------------------------

import sys

fibo = [1, 1, 2]

T = int(sys.stdin.readline())

mem = 3
for _ in range(T):
    N = int(sys.stdin.readline())

    while mem <= N:
        fibo.append(fibo[mem - 1] + fibo[mem - 2] + fibo[mem - 3])
        mem += 1
    
    print(fibo[N])
