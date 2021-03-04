# --------------------------------------
# 1로 만들기
# --------------------------------------


N = int(input())
DP = [0]

for i in range(1, N + 1):
    if i == 1:
        DP.append(0)
    else:
        if i % 3 == 0 and i % 2 == 0:
            DP.append(min(DP[i // 3], DP[i // 2]) + 1)
        elif i % 3 == 0:
            DP.append(min(DP[i // 3], DP[i - 1]) + 1)
        elif i % 2 == 0:
            DP.append(min(DP[i // 2], DP[i -1]) + 1)
        else:
            DP.append(DP[i - 1] + 1)

print(DP[N])


# 다른 풀이 방법
N = int(input())
DP = [0, 0]

for i in range(2, N + 1):
    DP.append(DP[i - 1] + 1)

    if i % 2 == 0:
        DP[i] = min(DP[i], DP[i // 2] + 1)
    if i % 3 == 0:
        DP[i] = min(DP[i], DP[i // 3] + 1)

print(DP[N])