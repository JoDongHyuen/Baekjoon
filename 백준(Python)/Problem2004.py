# --------------------------------------
# 조합 0의 개수
# --------------------------------------
n, m = map(int, input().split())

two_count = 0
five_count = 0

temp = n
while temp != 0:
    five_count = five_count + (temp // 5)
    temp //= 5

temp = n
while temp != 0:
    two_count = two_count + (temp // 2)
    temp //= 2

temp = m
while temp != 0:
    five_count = five_count - (temp // 5)
    temp //= 5

temp = m
while temp != 0:
    two_count = two_count - (temp // 2)
    temp //= 2

temp = n - m
while temp != 0:
    five_count = five_count - (temp // 5)
    temp //= 5

temp = n - m
while temp != 0:
    two_count = two_count - (temp // 2)
    temp //= 2


print(min(two_count, five_count))

