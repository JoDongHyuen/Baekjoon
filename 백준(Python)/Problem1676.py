import math
N = int(input())
Zero_Num = 0

while N:
    Zero_Num = Zero_Num + N // 5
    N //= 5

print(Zero_Num)

print(math.factorial(50))