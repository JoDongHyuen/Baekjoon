# --------------------------------------
# 쉬운 계단 수
# --------------------------------------

# 테이블 완전히 잘못 세움;;
# N = int(input())
# DP = [9]
# fibo0 = [0, 1]
# fibo9 = [1, 1]

# for i in range(1, N):
#     if i > 1:
#         fibo9.append((fibo9[i - 1] + fibo9[i - 2]) % 1000000000)
#         fibo0.append((fibo0[i - 1] + fibo0[i - 2]) % 1000000000)
#     DP.append((DP[i - 1] * 2 - fibo9[i - 1] - fibo0[i - 1]) % 1000000000)


# print(DP[N - 1])

N = int(input())
DP = [[0 for col in range(100)] for row in range(10)]

for i in range(1, 10):
    DP[i][0] = 1

for i in range(1, N):
    for j in range(10):
        if j == 0:
            DP[j][i] = DP[1][i - 1]
        elif j == 9:
            DP[j][i] = DP[8][i - 1]
        else:
            DP[j][i] = (DP[j - 1][i - 1] + DP[j + 1][i - 1]) % 1000000000

dp_sum = 0
for i in range(10):
    dp_sum += DP[i][N - 1] % 1000000000
print(dp_sum % 1000000000)
