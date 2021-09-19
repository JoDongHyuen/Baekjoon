# --------------------------------------
# 사이클 게임
# --------------------------------------

import sys

class DS:
    def __init__(self, size) -> None:
        self.parent = [-1 for _ in range(size)]

    def Union(self, i, j):
        temp = self.parent[i] + self.parent[j]

        if self.parent[i] > self.parent[j]:
            self.parent[i] = j
            self.parent[j] = temp
        else:
            self.parent[j] = i
            self.parent[i] = temp

    def Find(self, i):
        r = i
        while self.parent[r] >= 0:
            r = self.parent[r]

        while i != r:
            s = self.parent[i]
            self.parent[i] = r
            i = s

        return r

n , m = map(int, sys.stdin.readline().split())

check = False
sets = DS(n)

for i in range(1, m + 1):
    p1, p2 = map(int, sys.stdin.readline().split())

    p = sets.Find(p1)
    q = sets.Find(p2)

    if p != q:
        sets.Union(p, q)
    else:
        check = i
        break

if check:
    print(check)
else:
    print(0)