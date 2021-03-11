# --------------------------------------
# 평범한 배낭
# --------------------------------------

N, M = map(int, input().split())

DP = [[0 for i in range(M + 1)] for j in range(N + 1)]

for i in range(1, N + 1):
    weight, value = map(int, input().split())
    for j in range(1, M + 1):
        if weight > j:
            DP[i][j] = DP[i -1][j]
        else:
            DP[i][j] = max(DP[i -1][j], value + DP[i - 1][j - weight])

print(DP[N][M])
