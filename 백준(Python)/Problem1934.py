# --------------------------------------
# 최소공배수
# --------------------------------------

Test_Case = int(input())
for i in range(Test_Case):
    num1, num2 = map(int, input().split())
    temp1 = max(num1, num2)
    temp2 = min(num1, num2)

    while (temp1 % temp2 != 0):
        temp1 = temp1 % temp2
        temp1, temp2 = temp2, temp1
    
    print(num1 * num2 // temp2)
