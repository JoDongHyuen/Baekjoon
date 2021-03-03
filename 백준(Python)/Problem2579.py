# --------------------------------------
# 계단 오르기
# --------------------------------------

Step_Num = int(input())
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

# ------------------------------------
# 새로운 풀이
# ------------------------------------
Step_Num = int(input())
Step_Score = []
dp = []

for i in range(Step_Num):
    Score = int(input())
    Step_Score.append(Score)
    if i == 0:
        dp.append(Score)
    elif i == 1:
        dp.append(dp[0] + Score)
    elif i == 2:
        dp.append(max(dp[0] + Score, Step_Score[1] + Score))
    else:
        # i번 째 계단을 밟았을 때
        # 첫 번째 인자는 연속해서 밟은 계단이 1개 일 때
        # 두 번째 인자는 연속해서 밟은 계단이 2개 일 때
        dp.append(max(dp[i - 2] + Score, dp[i - 3] + Step_Score[i - 1] + Score))

print(dp[Step_Num])