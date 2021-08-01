# -------------------------------------
# 패션왕 신해빈
# -------------------------------------

import sys

T = int(sys.stdin.readline())

for _ in range(T):
    clothes = int(sys.stdin.readline())
    closet = {}

    for __ in range(clothes):
        name, kinds = sys.stdin.readline().split()
        if kinds in closet:
            closet[kinds] += 1
        else:
            closet[kinds] = 2
    
    result = 1

    for value in closet.values():
        result *= value

    result -= 1

    print(result)
