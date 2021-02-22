# --------------------------------------
# 스위치 켜고 끄기
# --------------------------------------


Switch_Num = int(input())

arr = [int(x) for x in input().split()]

# print(arr) 이거 안지워서 계속 틀림;;

Human_Num = int(input())

for i in range(Human_Num):
    Gender, Num = map(int, input().split())
    if Gender == 1:
        for j in range(Num - 1, Switch_Num, Num):
            if arr[j] == 0:
                arr[j] = 1
            else:
                arr[j] = 0
    elif Gender == 2:
        Num -= 1
        if arr[Num] == 0:
            arr[Num] = 1
        else:
            arr[Num] = 0
        
        low = Num - 1
        high = Num + 1
        while ((low >= 0) & (high < Switch_Num)):
            if arr[low] == arr[high]:
                if arr[low] == 0:
                    arr[low] = 1
                else:
                    arr[low] = 0

                if arr[high] == 0:
                    arr[high] = 1
                else:
                    arr[high] = 0
                low -= 1
                high += 1
            else:
                break
                
                
for i in range(Switch_Num):
    print(arr[i], end=" ")
    if (i + 1) % 20 == 0:
        print("")