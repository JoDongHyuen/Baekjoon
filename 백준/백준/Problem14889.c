#include <stdio.h>
#include <math.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int STAT[20][20] = { 0 };
int TEAM[20] = { 0 };
int Used_Check[20] = { 0 };
int MIN_GAP = 1000000;

int Problem14889_Backtracking(int depth, int pos, int value)
{
	int i, j, temp;
	int result, Team1_Sum, Team2_Sum;
	
	if (pos == (depth / 2))
	{
		temp = pos;
		for (i = 0; i < depth; i++)
			if (Used_Check[i] == 0)
				TEAM[temp++] = i;

		Team1_Sum = 0, Team2_Sum = 0;
		for (i = 0; i < (depth / 2); i++)
			for (j = i; j < (depth / 2); j++) {
				if (i != j) {
					Team1_Sum = Team1_Sum + STAT[TEAM[i]][TEAM[j]] + STAT[TEAM[j]][TEAM[i]];
					Team2_Sum = Team2_Sum + STAT[TEAM[i + (depth / 2)]][TEAM[j + (depth / 2)]] + STAT[TEAM[j + (depth / 2)]][TEAM[i + (depth / 2)]];
				}
			}
		result = abs(Team1_Sum - Team2_Sum);
		MIN_GAP = MIN(MIN_GAP, result);
	}
	else
	{
		for(i = value; i < depth; i++)
			if (Used_Check[i] == 0)
			{
				Used_Check[i] = 1;
				TEAM[pos] = i;
				Problem14889_Backtracking(depth, pos + 1, i);
				Used_Check[i] = 0;
			}
	}
}

int Problem14889()
{
	int Human_Num;
	int i, j;

	/* 입력 파트 */
	scanf("%d", &Human_Num);
	for (i = 0; i < Human_Num; i++)
		for (j = 0; j < Human_Num; j++)
			scanf("%d", &STAT[i][j]);

	/* 백트래킹 파트 */
	Problem14889_Backtracking(Human_Num, 0, 0);

	/* 출력 파트 */
	printf("%d\n", MIN_GAP);
}