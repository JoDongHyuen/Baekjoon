# --------------------------------------
# 연속합
# --------------------------------------

import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

# 내 풀이
# result = arr[0]
# now = False
# i = 0
# while i < N:
#     if now == False:
#         now = arr[i]
#     else:
#         now = now + arr[i]
    
#     if now > result :
#         result = now
#     if now <= 0 :
#         now = False   
#     i += 1

# 아래처럼 리팩토링 가능
result = arr[0]
now = arr[0]

for i in range(1, N):
    now = max(now + arr[i], arr[i])
    result = max(now, result)

print(result)