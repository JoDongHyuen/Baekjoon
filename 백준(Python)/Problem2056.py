# --------------------------------------
# 작업
# --------------------------------------

import bisect
import sys

N = int(sys.stdin.readline())
dp = [0]

for i in range(1, N + 1):
    input = list(map(int, sys.stdin.readline().split()))

    if input[1] == 0:
        dp.append(input[0])
    else:
        schedule = []
        for j in range(input[1]): # 시간 초과 나면 이거 우선순위 큐나 이진 탐색으로 변경
            schedule.append(dp[input[j + 2]])
        dp.append(max(schedule) + input[0])

print(max(dp))
