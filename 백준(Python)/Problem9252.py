# -------------------------------------
# LCS 2
# -------------------------------------

from collections import deque
import sys

A = str(sys.stdin.readline().strip())
B = str(sys.stdin.readline().strip())
result = []

dp = [[0 for col in range(len(A) + 1)] for row in range(len(B) + 1)]
# 0 : 자기자신, 1 : 대각선, 2 : 위, 3 : 좌측
tracking = [[0 for col in range(len(A) + 1)] for row in range(len(B) + 1)]

for row in range(1, len(B) + 1):
    for col in range(1, len(A) + 1):
        if A[col - 1] == B[row - 1]:
            dp[row][col] = dp[row -1][col -1] + 1
            tracking[row][col] = 1
        else:
            dp[row][col] = max(dp[row -1][col], dp[row][col - 1])

            if dp[row -1][col] > dp[row][col - 1]:
                tracking[row][col] = 2
            elif dp[row -1][col] == dp[row][col - 1]:
                tracking[row][col] = 2
            else:
                tracking[row][col] = 3


row = len(B)
col = len(A)
LCS = deque()

while tracking[row][col] != 0:
    check = tracking[row][col]

    if check == 1:
        LCS.appendleft(A[col - 1])
        row -= 1
        col -= 1
    elif check == 2:
        row -= 1
    else:
        col -= 1


print(dp[len(B)][len(A)])
print("".join(LCS))

# dp를 숫자가 아니라 "" 로 선언해서 대각선으로 이동할 때마다 string을 추가하는 방법도 있음
# 이건 진짜 아이디어가 멋지다!

from collections import deque
import sys

A = list(sys.stdin.readline().strip())
B = list(sys.stdin.readline().strip())
result = []

dp = [["" for col in range(len(A) + 1)] for row in range(len(B) + 1)]

for row in range(1, len(B) + 1):
    for col in range(1, len(A) + 1):
        if A[col - 1] == B[row - 1]:
            dp[row][col] = dp[row -1][col -1] + A[col - 1]
        else:
            if len(dp[row -1][col]) > len(dp[row][col - 1]):
                dp[row][col] = dp[row -1][col]
            else:
                dp[row][col] = dp[row][col - 1]

print(len(dp[len(B)][len(A)]))
print(dp[len(B)][len(A)])
