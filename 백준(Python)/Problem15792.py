# --------------------------------------
# A / B - 2
# -------------------------------------- 

A, B = map(int, input().split())

print(int(A/B), end=".")

for i in range(1001):
    A %= B 
    A *= 10
    print(int(A/B), end="")
    
