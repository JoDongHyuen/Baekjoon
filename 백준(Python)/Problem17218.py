# --------------------------------------
# 비밀번호 만들기
# -------------------------------------- 

import sys

str1 = sys.stdin.readline().strip()
str2 = sys.stdin.readline().strip()

dp = [["" for col in range(len(str1) + 1)] for row in range(len(str2) + 1)]

for row in range(len(str2)):
    for col in range(len(str1)):
        if str1[col] == str2[row]:
            dp[row + 1][col + 1] = dp[row][col] + str1[col]
        elif len(dp[row][col + 1]) > len(dp[row + 1][col]):
            dp[row + 1][col + 1] = dp[row][col + 1]
        else:
            dp[row + 1][col + 1] = dp[row + 1][col]

print(dp[len(str2)][len(str1)])