N = int(input())
Num = 1
for i in range(1, N + 1):
    Num = Num * i
    while Num % 10 == 0:
        Num = Num // 10
    Num = Num % 100000

print(Num % 10)
