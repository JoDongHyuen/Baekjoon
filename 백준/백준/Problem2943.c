#include<stdio.h>

typedef struct _stack {
	int Height;
	int Recp_Tower;
}Stack;

Stack Stack_Tower[500000];
int Problem2943_Top = -1;

void Problem2943_Push(int value)
{
	int i;

	if (Problem2943_Top == -1)
	{
		Stack_Tower[++Problem2943_Top].Height = value;
		Stack_Tower[Problem2943_Top].Recp_Tower = 0;
	}
	else
	{
		for (i = Problem2943_Top; i >= 0; i--) {
			if (Stack_Tower[i].Height < value && Stack_Tower[i].Recp_Tower == 0)
			{
				Stack_Tower[++Problem2943_Top].Height = value;
				Stack_Tower[Problem2943_Top].Recp_Tower = 0;
				break;
			}
			else if (Stack_Tower[i].Height > value)
			{
				Stack_Tower[++Problem2943_Top].Height = value;
				Stack_Tower[Problem2943_Top].Recp_Tower = i + 1;
				break;
			}
		}
	}

}

int Problem2943()
{
	int Test_Case;
	int i, j, Tower_Height, count;

	scanf("%d", &Test_Case);

	for (i = 0; i < Test_Case; i++)
	{
		scanf("%d", &Tower_Height);
		Problem2943_Push(Tower_Height);
	}

	for (i = 0; i < Test_Case; i++)
	{
		printf("%d ", Stack_Tower[i].Recp_Tower);
	}
}