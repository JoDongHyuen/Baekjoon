
# --------------------------------------
# 팰린드롬 수
# --------------------------------------

while True:

    flag = 0

    Arr = list(input())
    if Arr[0] == '0':
        break
    length = len(Arr)
    length -= 1
    Idx = length // 2 + 1

    for i in range(Idx):
        if Arr[i] != Arr[length - i]:
            flag = 1

    if flag == 0:
        print("yes")
    else:
        print("no")

