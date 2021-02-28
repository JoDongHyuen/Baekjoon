# -------------------------------------
# 파도반 수열
# -------------------------------------

Test_Case = int(input())

Padovan = [0 for x in range(100)]

for i in range(100):
    if i == 0 or i == 1 or i == 2:
        Padovan[i] = 1
    else:
        Padovan[i] = Padovan[i - 2] + Padovan[i - 3]

for i in range(Test_Case):
    N = int(input())
    print(f"{Padovan[N - 1]}")
