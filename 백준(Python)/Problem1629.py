# --------------------------------------
# 곱셈
# --------------------------------------
def Solution(A, B, C):
    if B == 1:
        return A % C
    elif B % 2 == 1:
        return (Solution(A, B//2, C) ** 2 * Solution(A, 1, C)) % C
    else:
        return (Solution(A, B//2, C) ** 2) % C

A, B, C = map(int, input().split())
print(Solution(A, B, C))
