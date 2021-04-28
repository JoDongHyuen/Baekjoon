# --------------------------------------
# 듣보잡
# -------------------------------------- 
N, M = map(int, input().split())

Ever_See = set()
Ever_Listen = set()

for i in range(N):
    Ever_See.add(input())

for i in range(M):
    Ever_Listen.add(input())

Result = list(Ever_See.intersection(Ever_Listen))

Result.sort()

print(len(Result))
for i in Result:
    print(i)