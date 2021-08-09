# --------------------------------------
# 배수와 약수
# --------------------------------------

import sys

while True:
    A, B = map(int, sys.stdin.readline().split())

    if A == 0 and B == 0: break
    elif A < B and B % A == 0: print("factor")
    elif A > B and A % B == 0: print("multiple")
    else: print("neither")