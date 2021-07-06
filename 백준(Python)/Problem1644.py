# --------------------------------------
# 소수의 연속합
# --------------------------------------

import sys
import math

N = int(sys.stdin.readline())

dp = [0]
num = [True for _ in range(N + 1)]
num[0] = False
num[1] = False


# N 보다 작은 소수 찾기 (에라토스테네스의 채)
end = int(math.sqrt(N))
for i in range(2, end + 1):
    if num[i] == True:   
        sum = i + i
        while sum <= N:
            num[sum] = False
            sum += i

# 소수 prefix sum 배열 만들기
for i in range(2, N + 1):
    if num[i] == True:
        dp.append(dp[-1] + i)

# 투 포인터 실행
start = 1
end = 1
count = 0

while end < len(dp):
    temp = dp[end] - dp[start - 1]

    if temp == N:
        count += 1
        start += 1
    elif temp < N:
        end += 1
    elif temp > N:
        start += 1

# 결과 출력
print(count)