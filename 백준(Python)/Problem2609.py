# --------------------------------------
# 최대공약수와 최소공배수
# --------------------------------------

A, B = map(int, input().split())

if A == B:
    print(A)
    print(B)
else:
    if A > B:
        temp1 = A
        temp2 = B
    elif A < B:
        temp1 = B
        temp2 = A

    # 유클리드 호제법
    while True:
        temp1 = temp1 % temp2
        if temp1 == 0:
            GCD = temp2
            break
        else:
            temp1, temp2 = temp2, temp1
    A = A // GCD
    B = B // GCD

    LCM = A * B * GCD
    print(GCD)
    print(LCM)

# tab 안해서 자꾸 틀렸음
# A = A // GCD
# B = B // GCD

# LCM = A * B * GCD
# print(GCD)
# print(LCM)