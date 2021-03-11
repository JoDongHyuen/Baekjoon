# -------------------------------------
# 다면체
# -------------------------------------
import sys
read = sys.stdin.readline

N = int(input())

for i in range(N):
    V, E = map(int, read().split())
    print(2 - V + E)
