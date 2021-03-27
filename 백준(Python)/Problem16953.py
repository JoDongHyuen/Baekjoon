# --------------------------------------
# A -> B
# -------------------------------------- 


A, B = map(int, input().split())
count = 0
flag = 1
while A < B:
    if B % 10 == 1:
        B //= 10
        count += 1
    elif B % 2 == 0 :
        B //= 2
        count += 1
    else:
        flag = 0
        break

if A != B or flag == 0:
    print(-1)
else:
    print(count + 1)