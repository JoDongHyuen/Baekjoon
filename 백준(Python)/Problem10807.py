# -------------------------------------
# 개수 세기
# -------------------------------------

Number_Num = int(input())
Count = [0 for length in range(201)]

Arr = list(map(int, input().split()))

for i in range(Number_Num):
    Count[Arr[i] + 100] += 1

check = int(input())

print(Count[check + 100])
