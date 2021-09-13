# --------------------------------------
# 피보나치 수 6
# -------------------------------------- 

from collections import deque
import sys

fibo = {}

def fibo_dq(num):
    if num <= 2:
        return fibo[num]
    else:
        if num % 2 == 0:
            if not num in fibo:
                fibo[num] = (fibo_dq(num // 2) * (fibo_dq(num // 2) + 2 * fibo_dq(num // 2 - 1))) % 1000000007
            return fibo[num]

        else:
            if not num in fibo:
                fibo[num] = (fibo_dq((num + 1) // 2) ** 2 + fibo_dq((num - 1) // 2) ** 2) % 1000000007
            return fibo[num]

n = int(sys.stdin.readline())
fibo[0] = 0
fibo[1] = 1
fibo[2] = 1

result = fibo_dq(n)

print(result)