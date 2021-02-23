# --------------------------------------
# 분산 처리
# --------------------------------------
# Test_Case = int(input())

# 풀이 Ver.1 (허접한 풀이)
res_2 = [6, 2, 4, 8]
res_3 = [1, 3, 9, 7]
res_4 = [6, 4]
res_7 = [1, 7, 9, 3]
res_8 = [6, 8, 4, 2]
res_9 = [1, 9]

for i in range(Test_Case):
    base, exp = map(int, input().split())
    digit = base % 10

    # 이런 풀이는 별로 좋은 풀이는 아닌거 같음
    if digit == 0:
        print(10)
    elif digit == 1:
        print(1)
    elif digit == 2:
        print(res_2[exp%4])
    elif digit == 3:
        print(res_3[exp%4])
    elif digit == 4:
        print(res_4[exp%2])
    elif digit == 5:
        print(5)
    elif digit == 6:
        print(6)
    elif digit == 7:
        print(res_7[exp%4])
    elif digit == 8:
        print(res_8[exp%4])
    elif digit == 9:
        print(res_9[exp%2])


# 풀이 Ver.2 (만족스러운 풀이)
# idea : 모든 숫자는 4제곱 주기로 첫번째 자리가 순환한다!!
Test_Case = int(input())

for i in range(Test_Case):
    base, exp = map(int, input().split())
    
    exp = exp % 4 + 4  # 4를 더해주는 이유는 exp가 4의 배수면 결과가 0이라 a**0은 항상 1이 나옴
    res = 1
    for j in range(exp):
        res = (res * base) % 10
    
    if res == 0: # res 결과가 0 일 땐 10번째 컴퓨터로 처리해주어야함
        print(10)
    else:
        print(res)

