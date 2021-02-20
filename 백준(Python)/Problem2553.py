N = int(input())
Num = 1
for i in range(1, N + 1):
    Num = Num * i
    if Num % 1000000 == 0:
        Num = Num // 1000000

while Num % 10 == 0:
    Num = Num // 10

print(Num % 10)
