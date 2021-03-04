# --------------------------------------
# 카드2
# --------------------------------------
# 시간 초과 코드
N = int(input())

Card = list(range(1, N +1))

while len(Card) != 1:
    Card.pop(0)
    Card.append(Card[0])
    Card.pop(0)

print(Card[0])

# ------------------------------------------- #
# collection 모듈 활용
from collections import deque
N = int(input())

Card = deque(range(1, N +1))

while len(Card) != 1:
    Card.popleft()
    Card.append(Card[0])
    Card.popleft()

print(Card[0])