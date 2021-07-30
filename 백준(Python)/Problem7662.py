# --------------------------------------
# 이중 우선순위 큐
# --------------------------------------

import heapq
import sys

T = int(sys.stdin.readline())

for _ in range(T):
    min_heap = []
    max_heap = []
    checker = {}
    count = 0
    
    N = int(sys.stdin.readline())
    for i in range(N):
        cmd, num = map(str, sys.stdin.readline().split())
        num = int(num)

        if cmd == 'I':
            heapq.heappush(min_heap, num)
            heapq.heappush(max_heap, -num)
            if num in checker :
                checker[num] += 1
            else :
                checker[num] = 1
            count += 1
        
        elif count == 0 :
            continue

        elif num == 1:
            while True :
                max_value = heapq.heappop(max_heap) * -1
                if checker[max_value] >= 1:
                    checker[max_value] -= 1
                    break
            count -= 1
            
        
        elif num == -1:
            while True :
                min_value = heapq.heappop(min_heap)
                if checker[min_value] >= 1:
                    checker[min_value] -= 1
                    break
            count -= 1
    
    if count == 0:
        print("EMPTY")
    else :
        while True :
            max_value = heapq.heappop(max_heap) * -1
            if checker[max_value] >= 1:
                break
        
        while True :
            min_value = heapq.heappop(min_heap)
            if checker[min_value] >= 1:
                break
        
        print(f"{max_value} {min_value}")

    



