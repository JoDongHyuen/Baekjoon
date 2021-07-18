# --------------------------------------
# 집합
# -------------------------------------- 

import sys

Set = [False for _ in range(21)]

M = int(sys.stdin.readline())

for _ in range(M):
    text = sys.stdin.readline().strip()
    cmd = text.split()[0]

    if cmd == "add":
        num = int(text.split()[1])
        Set[num] = True
    
    elif cmd == "remove":
        num = int(text.split()[1])
        Set[num] = False
    
    elif cmd == "toggle":
        num = int(text.split()[1])
        if Set[num]:
            Set[num] = False
        else:
            Set[num] = True
    
    elif cmd == "check":
        num = int(text.split()[1])
        if Set[num]:
            print(1)
        else:
            print(0)
    
    elif cmd == "all":
        Set = [True] * 21

    elif cmd == "empty":
        Set = [False] * 21