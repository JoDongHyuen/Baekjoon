# --------------------------------------
# 링
# --------------------------------------

import math
import sys

N = int(sys.stdin.readline())
rings = list(map(int, sys.stdin.readline().split()))

for i in range(1, N):
    gcd = math.gcd(rings[0], rings[i])
    print("{}/{}".format(rings[0] // gcd, rings[i] // gcd))
