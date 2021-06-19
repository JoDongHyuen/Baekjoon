# --------------------------------------
# 이항 계수 3
# -------------------------------------- 

def partition_multi(base, exp):
    if exp == 1:
        return base 

    elif exp % 2 == 1:
        return ((partition_multi(base, exp // 2) ** 2) * base) % 1000000007
    
    else:
        return partition_multi(base, exp // 2) ** 2 % 1000000007

import sys

N, K = map(int, sys.stdin.readline().split())


A = 1
B = 1

for num in range(2, N + 1):
    A *= num
    A %= 1000000007

for num in range(2, K + 1):
    B *= num
    B %= 1000000007

for num in range(2, N - K + 1):
    B *= num
    B %= 1000000007

B = partition_multi(B, 1000000005)

result = A * B % 1000000007

print(result)