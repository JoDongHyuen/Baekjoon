#include <stdio.h>
#include <math.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int NUMBER_ARR[11] = { 0 };
int USED_CHECK[10] = { 0 };
int OPERATOR[10];
int MAX_RESULT = -1000000001, MIN_RESULT = 1000000001;

void Problem14888_Backtracking(int depth, int pos, int result)
{
	int i;
	if (pos == depth)
	{
		MAX_RESULT = MAX(MAX_RESULT, result);
		MIN_RESULT = MIN(MIN_RESULT, result);

		return;
	}
	else
	{
		for (i = 0; i < depth; i++)
		{
			if (USED_CHECK[i] == 0)
			{
				USED_CHECK[i] = 1;
				switch (OPERATOR[i])
				{
				case 0:
					Problem14888_Backtracking(depth, pos + 1, result + NUMBER_ARR[pos + 1]);
					break;
				case 1:
					Problem14888_Backtracking(depth, pos + 1, result - NUMBER_ARR[pos + 1]);
					break;
				case 2:
					Problem14888_Backtracking(depth, pos + 1, result * NUMBER_ARR[pos + 1]);
					break;
				case 3:
					Problem14888_Backtracking(depth, pos + 1, result / NUMBER_ARR[pos + 1]);
					break;
				}
				USED_CHECK[i] = 0;
			}
		}
	}
}

int Problem14888()
{
	int Number_Num, Operator_Num = 0, Check_Operator;
	int i, j, pos = 0;

	/* ÀÔ·Â °ª */
	scanf("%d", &Number_Num);
	for (i = 0; i < Number_Num; i++)
		scanf("%d", &NUMBER_ARR[i]);

	for (i = 0; i < 4; i++)
	{
		scanf("%d", &Check_Operator);
		for (j = 0; j < Check_Operator; j++)
			OPERATOR[Operator_Num++] = i;
	}

	Problem14888_Backtracking(Operator_Num, 0, NUMBER_ARR[0]);
	
	printf("%d\n%d", MAX_RESULT, MIN_RESULT);
}
