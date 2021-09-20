# --------------------------------------
# 행성 터널
# --------------------------------------

import heapq
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

N = int(sys.stdin.readline())
result = 0
points = []
sets = DS(N + 1)
F = 0
pq = []

for i in range(N):
    input = list(map(int, sys.stdin.readline().split()))
    input.append(i)
    points.append(input)

# 이렇게 하면 메모리 초과 발생함
# for i in range(1, N + 1):
#     for j in range(i + 1, N + 1):
#         distance = min(abs(points[i][0] - points[j][0]), abs(points[i][1] - points[j][1]), abs(points[i][2] - points[j][2]))
#         heapq.heappush(pq, (distance, i, j))

points.sort(key=lambda x: x[0])
for i in range(1, N):
    distance = abs(points[i][0] - points[i - 1][0])
    heapq.heappush(pq, (distance, points[i][3], points[i - 1][3]))

points.sort(key=lambda x: x[1])
for i in range(1, N):
    distance = abs(points[i][1] - points[i - 1][1])
    heapq.heappush(pq, (distance, points[i][3], points[i - 1][3]))

points.sort(key=lambda x: x[2])
for i in range(1, N):
    distance = abs(points[i][2] - points[i - 1][2])
    heapq.heappush(pq, (distance, points[i][3], points[i - 1][3]))

while F < (N - 1):
    distance, p1, p2 = heapq.heappop(pq)

    p = sets.Find(p1)
    q = sets.Find(p2)

    if p != q:
        F += 1
        result += distance
        sets.Union(p, q)

print(result)