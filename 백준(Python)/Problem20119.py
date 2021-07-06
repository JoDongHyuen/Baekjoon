# --------------------------------------
# 클레어와 물약
# -------------------------------------- 
from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())
recipe = []
pre = [[] for _ in range(N + 1)] 
check = [False for _ in range(N + 1)]

for i in range(M):
    input = list(map(int, sys.stdin.readline().split()))
    recipe.append([input[0], input[-1]])

    for num in input[1:-1]:
        pre[num].append(i)
    
L = int(sys.stdin.readline())
y = list(map(int, sys.stdin.readline().split()))

queue = deque()

for num in y:
    queue.append(num)
    check[num] = True

while queue:
    index = queue.popleft()

    for num in pre[index]:
        recipe[num][0] -= 1


        if recipe[num][0] == 0 and check[recipe[num][1]] == False:
            queue.append(recipe[num][1])
            check[recipe[num][1]] = True

print(sum(check))
for i in range(N + 1):
    if check[i]:
        print(i, end=" ")