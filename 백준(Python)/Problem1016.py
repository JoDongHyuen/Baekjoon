# --------------------------------------
# 제곱 ㄴㄴ 수
# --------------------------------------

import sys
import math

min, max = map(int, sys.stdin.readline().split())

check = [True for _ in range(max - min + 1)]

num = 2
while num ** 2 <= max:
    exp = num ** 2

    now = 0

    if min % exp == 0:
        now = min
    else:
        now = (min // exp + 1) * exp
    
    # 이 부분 반례 : 36 45 입력하면 45를 못 거름
    # if now <= max and check[now - min] == False:
    #     num += 1
    #     continue
    
    while now <= max:
        check[now - min] = False
        # print(now)
        now += exp

    num += 1

print(sum(check))