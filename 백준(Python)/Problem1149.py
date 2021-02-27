# --------------------------------------
# RGB 거리
# --------------------------------------

Test_Case = int(input())
RGB = []
result = 0

for i in range(Test_Case):
    if i == 0:
        RGB.append([])
        R, G, B = map(int, input().split())
        RGB[0].append(R)
        RGB[0].append(G)
        RGB[0].append(B)

    else:
        RGB.append([])
        R, G, B = map(int, input().split())
        R_min = R + min(RGB[i - 1][1], RGB[i - 1][2])
        G_min = G + min(RGB[i - 1][0], RGB[i - 1][2]) 
        B_min = B + min(RGB[i - 1][0], RGB[i - 1][1])
        RGB[i].append(R_min)
        RGB[i].append(G_min)
        RGB[i].append(B_min)

print(f"{min(RGB[i][0], RGB[i][1], RGB[i][2])}")
