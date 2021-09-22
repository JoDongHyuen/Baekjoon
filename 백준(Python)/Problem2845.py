# --------------------------------------
# 파티가 끝나고 난 뒤
# --------------------------------------

import sys

L, P = map(int, sys.stdin.readline().split())
num = L * P

lista = list(map(int, sys.stdin.readline().split()))

for i in range(5):
    lista[i] -= num

print(*lista)