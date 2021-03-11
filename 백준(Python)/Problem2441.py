# --------------------------------------
# 별 찍기 - 4
# --------------------------------------

N = int(input())

for i in range(N):
    for j in range(N):
        if (i<=j):
            print("*", end="")
        else:
            print(" ", end="")
    print("")