# --------------------------------------
# 다리 놓기
# --------------------------------------

Test_Case = int(input())

Bridge = [[0 for col in range(31)] for row in range(31)]

for i in range(31):
    Bridge[1][i] = i
    Bridge[i][i] = 1

for i in range(2, 31):
    for j in range(i + 1, 31):
        Bridge[i][j] = Bridge[i][j - 1] + Bridge[i - 1][j - 1]


for i in range(Test_Case):
    West_Base, East_Base = map(int, input().split())
    print(Bridge[West_Base][East_Base])
