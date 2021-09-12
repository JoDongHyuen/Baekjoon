# --------------------------------------
# 행렬 제곱
# --------------------------------------

import sys

def matrix_mul(a, b, size):
    res = [[0 for _ in range(size)] for __ in range(size)]

    for i in range(size):
        for j in range(size):
            for k in range(size):
                res[i][j] += a[i][k] * b[k][j]
            res[i][j] %= 1000
    
    return res

def matrix_sqrt(m, size, pow):
    if pow == 1:
        return m
    else:
        if pow % 2 == 1:
            temp = matrix_sqrt(m, size, pow // 2)
            temp2 = matrix_mul(temp, temp, size)
            result = matrix_mul(temp2, m, size)

            return result

        else:
            temp = matrix_sqrt(m, size, pow // 2)
            result = matrix_mul(temp, temp, size)

            return result

N, B = map(int, sys.stdin.readline().split())
matrix = []

for _ in range(N):
    matrix.append(list(map(int, sys.stdin.readline().split())))

# B가 1인 경우, element가 1000인 경우 그대로 출력하는 것을 방지..!
for i in range(N):
    for j in range(N):
        matrix[i][j] %= 1000

result = matrix_sqrt(matrix, N, B)

for row in result:
    print(*row)