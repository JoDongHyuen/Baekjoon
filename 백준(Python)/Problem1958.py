# --------------------------------------
# LCS 3
# --------------------------------------


import sys

A = str(sys.stdin.readline().strip())
B = str(sys.stdin.readline().strip())
C = str(sys.stdin.readline().strip())


dp = [[[0 for col in range(len(A) + 1)] for row in range(len(B) + 1)] for floor in range(len(C) + 1)]

for z in range(1, len(C) + 1):
    for x in range(1, len(B) + 1):
        for y in range(1, len(A) + 1):
            if C[z - 1] == B[x - 1] and B[x - 1] == A[y - 1]:
                dp[z][x][y] = dp[z-1][x-1][y-1] + 1
            else:
                dp[z][x][y] = max(dp[z - 1][x][y], dp[z][x - 1][y], dp[z][x][y - 1])

print(dp[-1][-1][-1])
