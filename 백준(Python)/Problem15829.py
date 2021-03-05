# --------------------------------------
# Hashing
# -------------------------------------- 

L = int(input())
arr = list(input())
arr = list(map(ord, arr))
M = 1
Sum = 0
for i in range(L):
    value = (arr[i] - 96) * M
    M = M * 31 % 1234567891
    Sum = (Sum + value) % 1234567891
print(Sum)


