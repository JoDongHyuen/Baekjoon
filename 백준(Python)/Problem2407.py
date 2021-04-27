# --------------------------------------
# 조합
# --------------------------------------

n, m = input().split()

DP = [[0 for cols in range(101)] for rows in range(101)]

for i in range(1, 101):
    DP[i][i] = 1
    DP[i][1] = i

for i in range(3, 101):
    for j in range(2, i):
        DP[i][j] = DP[i -1][j] + DP[i - 1][j - 1]

print(DP[int(n)][int(m)])


