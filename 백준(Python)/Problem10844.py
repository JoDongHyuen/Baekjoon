# --------------------------------------
# 쉬운 계단 수
# --------------------------------------

N = int(input())
DP = [9]
fibo =[1, 2]

for i in range(1, N):
    DP.append((DP[i - 1] * 2 - fibo[i - 1]) % 1000000000)
    if i > 1:
        fibo.append(fibo[i - 2] + fibo[i - 1])


print(DP[N - 1])
