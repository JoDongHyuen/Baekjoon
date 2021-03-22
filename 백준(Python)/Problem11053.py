# --------------------------------------
# 가장 긴 증가하는 부분 수열
# -------------------------------------- 

N = int(input())
A = list(map(int, input().split()))
DP = [1 for x in range(1001)]

DP[0] = 1

for i in range(1, N):
    for j in range(0, i):
        if (A[j] < A[i]):
            DP[i] = max(DP[i], DP[j] + 1)

print(max(DP))