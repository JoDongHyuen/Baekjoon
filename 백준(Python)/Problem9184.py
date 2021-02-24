# -------------------------------------
# 신나는 함수 실행
# -------------------------------------

arr = [[[0 for x in range(21)] for y in range(21)] for z in range(21)]

for i in range(21):
    for j in range(21):
        arr[0][i][j] = 1
        arr[i][0][j] = 1
        arr[i][j][0] = 1

for i in range(1, 21):
    for j in range(1, 21):
        for k in range(1, 21):
            if (i < j & j < k):
                arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k]
            else:
                arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1]

while True:
    a, b, c = map(int, input().split())
    
    if (a == -1 & b == -1 & c == -1):
        break
    elif (a <= 0) | (b <= 0) | (c <= 0):
        print(f"w({a}, {b}, {c}) = {arr[0][0][0]}")
    elif (a > 20) | (b > 20) | (c > 20):
        print(f"w({a}, {b}, {c}) = {arr[20][20][20]}")
    else:
        print(f"w({a}, {b}, {c}) = {arr[a][b][c]}")
