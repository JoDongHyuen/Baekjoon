N = int(input())
Num = 1
for i in range(1, N + 1):
    Num = Num * i
    while Num % 10 == 0:
        Num = Num // 10
    Num = Num % 1000000  # 0이 아닌 뒷부분을 어느정도 챙기느냐에 따라 예측할 수 있는 N!의 범위가 늘어남

print(Num % 10)
