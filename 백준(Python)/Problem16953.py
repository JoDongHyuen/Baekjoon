# --------------------------------------
# A -> B
# -------------------------------------- 


A, B = map(int, input().split())
count = 0

while A < B:
    if B % 10 == 1:
        B //= 10
        count += 1
    elif B % 2 == 0 :
        B //= 2
        count += 1
    else:
        break

if A != B:
    print(-1)
else:
    print(count + 1)