# -------------------------------------
# 별자리
# --------------------------------------

import sys
import heapq
import math

class DS:
    def __init__(self, size):
        self.parent = [-1 for _ in range(size + 1)]

    def Union(self, a, b):
        temp = self.parent[a] + self.parent[b]

        if self.parent[a] > self.parent[b]:
            self.parent[a] = b
            self.parent[b] = temp
        else:
            self.parent[b] = a
            self.parent[a] = temp

    def Find(self, a):
        r = a
        while(self.parent[r] > 0):
            r = self.parent[r]
        
        while a != r:
            s = self.parent[a]
            self.parent[a] = r
            a = s
        
        return r


N = int(sys.stdin.readline())
disjoint = DS(N)
points = [0]
pq = []

for _ in range(N):
    points.append(list(map(float, sys.stdin.readline().split())))

for p1 in range(1, N + 1):
    for p2 in range(p1 + 1, N + 1):
        x = points[p1][0] - points[p2][0]
        y = points[p1][1] - points[p2][1]
        distance = math.sqrt(x * x + y * y)
        heapq.heappush(pq, (distance, p1, p2))

F = 0
result = 0

while F < (N - 1):
    distance, p1, p2 = heapq.heappop(pq)

    p = disjoint.Find(p1)
    q = disjoint.Find(p2)

    if p != q:
        F += 1
        result += distance
        disjoint.Union(p, q)

print(result)