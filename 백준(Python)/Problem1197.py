# --------------------------------------
# 최소 스패닝 트리
# --------------------------------------

import sys

class DS:
    def __init__(self, size) -> None:
        self.parent = [-1 for _ in range(size + 1)]

    def Union(self, a, b):
        temp = self.parent[a] + self.parent[b]

        if self.parent[a] > self.parent[b]:
            self.parent[b] = temp
            self.parent[a] = b
        else:
            self.parent[a] = temp
            self.parent[b] = a

    def Find(self, i):
        r = i
        while self.parent[r] >= 0:
            r = self.parent[r]
        
        while i != r:
            s = self.parent[i]
            self.parent[i] = r
            i = s
        
        return r


V, E = map(int, sys.stdin.readline().split())
edges = []
sets = DS(V)

for _ in range(E):
    edges.append(list(map(int, sys.stdin.readline().split())))

edges.sort(key=lambda x : x[2])

F = 0
result = 0
for edge in edges:
    a, b, w = edge
    p = sets.Find(a)
    q = sets.Find(b)

    if p != q:
        result += w
        F += 1
        sets.Union(p,q)
    
    if F >= V - 1: break

print(result)