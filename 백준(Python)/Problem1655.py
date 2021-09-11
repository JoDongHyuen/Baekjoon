# --------------------------------------
# 가운데를 말해요
# --------------------------------------
# Maxheap의 크기가 Minheap의 크기보다 항상 크거나 같도록하기
# 두 힙의 크기 차이가 2이상 되지 않게 하기
# Maxheap의 top이 Minheap의 top보다 크면 두 값을 바꾸기

import heapq
import sys

now = -1
Maxheap = []
Minheap = []

N = int(sys.stdin.readline())

for _ in range(N):
    num = int(sys.stdin.readline())
    
    if len(Maxheap) == len(Minheap):
        heapq.heappush(Maxheap, -num)
    else:
        heapq.heappush(Minheap, num)

    if Maxheap and Minheap:
        if -(Maxheap[0]) > Minheap[0]:
            max = -heapq.heappop(Maxheap)
            min = heapq.heappop(Minheap)
            heapq.heappush(Maxheap, -min)
            heapq.heappush(Minheap, max)
    
    print(-Maxheap[0])
