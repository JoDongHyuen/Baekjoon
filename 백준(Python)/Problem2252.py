# --------------------------------------
# 줄 세우기
# --------------------------------------

from collections import deque
import sys

def typology(Link, Condition, N):
    queue = deque()
    result = []

    for i in range(1, N + 1):
        if Condition[i] == 0:
            queue.append(i)

    while queue:
        value = queue.popleft()
        result.append(value)

        for i in Link[value]:
            Condition[i] -= 1
            if Condition[i] == 0:
                queue.append(i)
    

    for i in result:
        print(i, end=" ")



N, M = map(int , sys.stdin.readline().split())

Link = [[] for _ in range(N + 1)]
Condition = [0 for _ in range(N + 1)]


for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    Link[A].append(B)
    Condition[B] += 1



typology(Link, Condition, N)