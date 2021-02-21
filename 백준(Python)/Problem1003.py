# --------------------------------------
# 피보나치 함수
# --------------------------------------
Test_Case = int(input())

fibo = []

fibo += [[1, 0]]
fibo += [[0, 1]]

for i in range(2, 41):
    Num_Zero = fibo[i - 1][0] + fibo[i - 2][0]
    Num_One = fibo[i - 1][1] + fibo[i - 2][1]
    fibo += [[Num_Zero, Num_One]]

for i in range(Test_Case):
    N = int(input())
    print(f"{fibo[N][0]} {fibo[N][1]}")

# 이 코드는 왜 모든 리스트의 0번째 인자를 1로 바꿀까?
# fibo = [[0]*2]*41
# fibo[0][0] = 1
# print(fibo)
# 참고 : https://www.geeksforgeeks.org/python-using-2d-arrays-lists-the-right-way/