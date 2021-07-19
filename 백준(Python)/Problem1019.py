# --------------------------------------
# 책 페이지
# --------------------------------------
from collections import deque
import sys

N = sys.stdin.readline().strip()
length = len(N)

num = int(N)
divide = 10**(length - 1)

number = [0] * 10
dp = [0]

for i in range(1, length):
    dp.append(dp[-1] * 10 + 10**(i - 1))

count = 1
queue = deque()
for i in N:

    digit = int(i)

    if count == 1:
        for j in range(1, 10):
            number[j] = number[j] + dp[length - count]
        
        temp = '1' * (length - 1)
        if not temp:
            temp = 0
        else:
            temp = int(temp)

        number[0] = dp[length - count] - temp

        if count != length:
            for j in range(1, digit):
                for k in range(0, 10):
                    number[k] += dp[length - count]
                number[j] += 10**(length - count)
        else:
            for j in range(1, digit + 1):
                number[j] += divide
        
        queue.append(digit)

    else:
        pre_digit = queue.pop()
        number[pre_digit] += num % divide + 1
        
        num %= divide
        divide //= 10

        if count != length:
            for j in range(0, digit):
                for k in range(0, 10):
                    number[k] += dp[length - count]
                number[j] += divide
        else:
            for j in range(0, digit + 1):
                number[j] += divide

        queue.append(digit)
    
    count += 1

print(*number)