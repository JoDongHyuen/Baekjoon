# --------------------------------------
# 우주신과의 교감
# -------------------------------------- 

import sys
import math
import heapq

class DS:
    def __init__(self, size):
        self.parent =  [-1 for _ in range(size + 1)]

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
        while self.parent[r] > 0:
            r = self.parent[r]

        while i != r:
            s = self.parent[i]
            self.parent[i] = r
            i = s

        return r    

N, M = map(int, sys.stdin.readline().split())

point = [0]
pq = []

sets = DS(N)
result = 0
F = 0
for _ in range(N):
    point.append(list(map(float, sys.stdin.readline().split())))

for _ in range(M):
    x, y = map(int, sys.stdin.readline().split())

    p = sets.Find(x)
    q = sets.Find(y)

    if p != q:
        sets.Union(p, q)
        F += 1

for i in range(1, N + 1):
    for j in range(i + 1, N + 1):
        x = point[i][0] - point[j][0]
        y = point[i][1] - point[j][1]
        distance = math.sqrt(x * x + y * y)
        heapq.heappush(pq, (distance, i, j))


while F < N - 1:
    distance, p1, p2 = heapq.heappop(pq)

    p = sets.Find(p1)
    q = sets.Find(p2)

    if p != q:
        sets.Union(p, q)
        result += distance
        F += 1

print("%.2f" % result)
