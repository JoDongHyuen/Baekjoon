# --------------------------------------
# 색깔 하노이 탑
# -------------------------------------- 

Tower_Height = int(input())

Move_Count = 2**(Tower_Height+2) - 5
Move_Count %= 1000000007

print(Move_Count)