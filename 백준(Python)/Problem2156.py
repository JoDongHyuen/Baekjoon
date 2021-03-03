# --------------------------------------
# 포도주 시식
# --------------------------------------

Wine_Num = int(input())
Wine_Amount = []

for i in range(Wine_Num):
    Wine_Amount.append([])
    Amount = int(input())
    if i == 0:
        Wine_Amount[i].append(Amount)
        Wine_Amount[i].append(Amount)
    elif i == 1:
        Wine_Amount[i].append(Amount)
        Wine_Amount[i].append(Amount + Wine_Amount[0][0])
    elif i == 2:
        Wine_Amount[i].append(Amount + Wine_Amount[0][0])
        Wine_Amount[i].append(Amount + Wine_Amount[1][0])
    else:
        Wine_Amount[i].append(Amount + max(Wine_Amount[i - 2][0], Wine_Amount[i - 2][1], Wine_Amount[i - 3][0], Wine_Amount[i - 3][1]))
        Wine_Amount[i].append(Amount + Wine_Amount[i - 1][0])

print(max(max(Wine_Amount[Wine_Num - 1]), max(Wine_Amount[Wine_Num - 2])))
