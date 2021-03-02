# --------------------------------------
# 계단 오르기
# --------------------------------------

Step_Num = int(input())
Step_Score = []
Step_Score_Max = []


for i in range(Step_Num):
    Step_Score_Max.append([])
    Score = int(input())
    if i == 0:
         Step_Score_Max[i].append(Score)
         Step_Score_Max[i].append(Score)
    elif i == 1:
        Step_Score_Max[i].append(Score)
        Step_Score_Max[i].append(Score + Step_Score_Max[i - 1][0])
    else:
        Step_Score_Max[i].append(Score + max(Step_Score_Max[i - 2][0], Step_Score_Max[i-2][1]))
        Step_Score_Max[i].append(Score + Step_Score_Max[i - 1][0])

print(max(Step_Score_Max[Step_Num - 1][0], Step_Score_Max[Step_Num - 1][1]))
