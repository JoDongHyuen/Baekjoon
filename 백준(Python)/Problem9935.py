# -------------------------------------
# 문자열 폭발
# -------------------------------------

from collections import deque
import sys

input = sys.stdin.readline().strip()
bomb = sys.stdin.readline().strip()

stack = deque()

for index in input:
    stack.append(index)
    
    if len(stack) >= len(bomb) and index == bomb[-1]:
        check_bomb = True
        for i in range(1, len(bomb)):
            if stack[-1 - i] == bomb[-1 - i]:
                continue
            else:
                check_bomb = False
                break
        
        if check_bomb:
            for _ in range(len(bomb)):
                stack.pop()

if stack:
    print(''.join(stack))
else:
    print("FRULA")

