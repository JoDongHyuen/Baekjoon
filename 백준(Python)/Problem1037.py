# --------------------------------------
# 약수
# --------------------------------------

Test_Case = int(input())

arr = [int(x) for x in input().split()]
arr = sorted(arr)  # sorted는 lvalue를 지정해주어야함, inplace하지 않음

print(arr[0] * arr[-1])

