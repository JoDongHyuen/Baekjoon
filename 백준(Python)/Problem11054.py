# --------------------------------------
# 가장 긴 바이토닉 부분 수열
# -------------------------------------- 

import bisect
import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

ascend = [0 for _ in range(N)]
up = []

decend = [0 for _ in range(N)]
down = []

for i in range(N):
    # 오름차순 연산
    index = bisect.bisect_left(up, arr[i])

    if index >= len(up):
        up.append(arr[i])
    else:
        up[index] = arr[i]
    
    ascend[i] = index + 1

    # 내림차순 연산
    index = bisect.bisect_left(down, arr[N - 1 - i])

    if index >= len(down):
        down.append(arr[N - 1 - i])
    else:
        down[index] = arr[N - 1 - i]

    decend[N - 1 - i] = index + 1

# 결과 도출
result = [ascend[i] + decend[i] - 1 for i in range(N)]
print(max(result))
