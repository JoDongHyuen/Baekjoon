# --------------------------------------
# 알파벳 개수
# --------------------------------------


string = input()
length = len(string)
Apb_Count = [0 for x in range(26)]

for idx in range(length):
    pos = ord(string[idx]) - 97
    Apb_Count[pos] += 1

for i in range(26):
    print(f"{Apb_Count[i]}", end=" ")

