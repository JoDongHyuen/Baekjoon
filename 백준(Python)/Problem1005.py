# --------------------------------------
# ACM Craft
# --------------------------------------

from collections import deque
import sys

def typology(N, Dp, Preq, Condition, Time):
    
    queue = deque()

    for i in range(1, N + 1):
        if Condition[i] == 0:
            queue.append(i)

    while queue:
        index = queue.popleft()

        for i in Preq[index]:
            Condition[i] -= 1
            Dp[i] = max(Dp[i], Dp[index]+ Time[i])

            if Condition[i] == 0:
                queue.append(i)
    


Test_Case = int(sys.stdin.readline())

for _ in range(Test_Case):
    N, K = map(int, sys.stdin.readline().split())

    Dp = [0]
    Preq = [[] for i in range(N + 1)]
    Condition = [0 for i in range(N + 1)]
    Dp.extend(list(map(int, sys.stdin.readline().split())))
    Time = Dp.copy()

    for i in range(K):
        X, Y = map(int, sys.stdin.readline().split())
        Preq[X].append(Y)
        Condition[Y] += 1

    W = int(sys.stdin.readline())

    typology(N, Dp, Preq, Condition, Time)

    print(Dp[W])