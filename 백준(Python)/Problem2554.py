# --------------------------------------
# 팩토리얼의 마지막 수 구하기2
# --------------------------------------

digit = [1, 1, 2, 6, 4, 2, 2, 4, 2, 8]

Num = int(input())

def solution(N):
    if N < 10:
        return digit[N]
    else:
        if (N // 10) % 2 == 0:
            return (6 * solution(N//5) * solution(N % 10)) % 10
        else:
            return (5 * solution(N//5) * solution(N % 10)) % 10

print(solution(Num))

# 참고 : https://math.stackexchange.com/questions/130352/last-non-zero-digit-of-a-factorial


# # 시간초과 ^_^;;
# N = int(input())

# Count_5 = 0
# temp = N

# # 팩토리얼의 5의 개수를 구하자
# # 5의 개수는 2의 개수보다 항상 적다!
# while temp:
#     Count_5 = Count_5 + temp // 5
#     temp //= 5

# Last_Digit = 1
# for i in range(1, N + 1):
#     multiply = i

#     # 5가 곱해지면 마지막 자리수만 가지고 연산했을 때
#     # 정확한 값이 나오지 않기 때문에 나눠줌
#     # But 5만 나누면 결과가 달라질 수 있음
#     while multiply % 5 == 0:
#         multiply //= 5

#     # 여기서 2도 함께 나누면 10을 나누게 되는거임
#     # But 5의 개수보다 많게 2를 나누면 결과가 달라지기에
#     # 5의 개수만큼만 2를 나눠야함
#     if Count_5 != 0 and multiply % 2 == 0:
#         Count_5 -= 1
#         multiply //= 2
    
#     # 0을 만들 수 있는 수가 들어올 때마다 제거를 해주면
#     # 마지막 자리만 가지고 연산 했을 때 옳은 결과가 나옴
#     Last_Digit = (Last_Digit * multiply) % 10

# print(Last_Digit)
