# --------------------------------------
# 문제집
# -------------------------------------- 

from collections import deque
import bisect
import sys

def typology(Count, Check, N):
    q = deque()
    result = []

    for i in range(1, N + 1):
        if Check[i] == 0:
            q.append(i)
    
    while q:
        value = q.popleft()
        result.append(value)

        for i in Count[value]:
            Check[i] -= 1
            if Check[i] == 0:
                index = bisect.bisect_right(q, i)
                q.insert(index, i)
    
    for i in result:
        print(i, end=" ")

N, M = map(int, sys.stdin.readline().split())

Count = [[] for _ in range(N + 1)]
Check = [0 for _ in range(N + 1)]

for x in range(M):
    A, B = map(int, sys.stdin.readline().split())
    Count[A].append(B)
    Check[B] += 1


typology(Count, Check, N)
