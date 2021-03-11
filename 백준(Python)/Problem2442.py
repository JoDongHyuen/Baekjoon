# --------------------------------------
# 별 찍기 - 5
# --------------------------------------

N = int(input())

for i in range(N):
    for j in range(1, i + N + 1):
        if abs(N - j) <= i:
            print("*", end="")
        else:
            print(" ", end="")
    print("")