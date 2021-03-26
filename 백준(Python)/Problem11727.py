# --------------------------------------
# 2 * n 타일링 2
# --------------------------------------
N = int(input())

DP = []
DP.append(1)
DP.append(3)

for i in range(2, N):
    DP.append((DP[i - 2] * 2 + DP[i - 1]) % 10007)

print(DP[N - 1])
