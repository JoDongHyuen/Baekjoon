# --------------------------------------
# 나누기
# --------------------------------------

N = int(input())
F = int(input())

N //= 100
N *= 100


if N % F == 0:
    print('{0:02d}'.format(0))
else:
    for i in range(1, 100):
        N += 1
        if N % F == 0:
            print('{0:02d}'.format(i))
            break