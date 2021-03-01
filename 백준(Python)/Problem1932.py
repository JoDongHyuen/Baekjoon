
# --------------------------------------
# 정수 삼각형
# --------------------------------------

Int_Tri = []
Result = []

size = int(input())
for i in range(size):
    # arr = int(input().split())  int()에 인자로 list 타입이 올 수 없음! input().split()는 list 타입을 반환함
    Int_Tri.append(list(map(int, input().split())))

for i in range(size):
    Result.append([])
    for j in range(i + 1):
        if i == 0 and j == 0:
            Result[i].append(Int_Tri[0][0])
        elif j == 0:
            Result[i].append(Result[i - 1][j] + Int_Tri[i][j])
        elif j == i:
            Result[i].append(Result[i - 1][j - 1] + Int_Tri[i][j])
        else:
            Result[i].append(max(Result[i - 1][j], Result[i - 1][j - 1]) + Int_Tri[i][j])

print(max(Result[size - 1]))