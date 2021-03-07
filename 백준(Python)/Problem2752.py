# --------------------------------------
# 세수정렬
# --------------------------------------

Num_Arr = list(map(int, input().split()))
Num_Arr = sorted(Num_Arr)

for i in range(3):
    print(Num_Arr[i], end=" ")