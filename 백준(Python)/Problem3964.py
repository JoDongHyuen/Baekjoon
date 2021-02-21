# -------------------------------------
# 팩토리얼과 거듭제곱 문제
# --------------------------------------
def solution(fact, sqrt):
    cnt = 0
    for i in range(1, fact + 1):
        num = i
        while True:
            if (num % sqrt) == 0:
                cnt += 1
                num //= sqrt
            else:
                break
    print(cnt)

Test_Case = int(input())

for i in range(Test_Case):
    Fact, Sqrt = map(int, input().split())
    solution(Fact, Sqrt)

# 해결 못함
