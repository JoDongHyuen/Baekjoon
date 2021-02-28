# --------------------------------------
# 01 타일
# --------------------------------------

tile_list = []

tile_num = int(input())

for i in range(tile_num):
    if i == 0:
        tile_list.append(1)
    elif i == 1:
        tile_list.append(2)
    else:
        tile_list.append((tile_list[i - 1] + tile_list[i - 2]) % 15746)

print(tile_list[tile_num - 1])