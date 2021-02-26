#include<stdio.h>

typedef struct _stack {
	int Height;
	int Recp_Tower;
	int Tower_Position;
}Stack;

Stack Stack_Tower[500000];
int Problem2943_Top = -1;

void Problem2943_pop()
{
	Problem2943_Top--;
}

void Problem2943_Push(int value, int Tower_Order)
{
	int i;

	if (Problem2943_Top == -1)
	{
		Stack_Tower[++Problem2943_Top].Height = value;
		Stack_Tower[Problem2943_Top].Tower_Position = Tower_Order + 1;
		printf("%d ", 0);
	}
	else
	{
		for (i = Problem2943_Top; i >= 0; i--) {
			if (Stack_Tower[i].Height < value)
				Problem2943_pop();	//pop이 왜 필요한지 고민해보니 배울점이 많았음
			else if (Stack_Tower[i].Height > value)
			{
				Stack_Tower[++Problem2943_Top].Height = value;
				Stack_Tower[Problem2943_Top].Tower_Position = Tower_Order + 1;
				printf("%d ", Stack_Tower[i].Tower_Position);
				break;
			}
		}
		if (i == -1)
		{
			Stack_Tower[++Problem2943_Top].Height = value;
			Stack_Tower[Problem2943_Top].Tower_Position = Tower_Order + 1;
			printf("%d ", 0);
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
		Problem2943_Push(Tower_Height, i);
	}
	/*
	for (i = 0; i < Test_Case; i++)
	{
		printf("%d ", Stack_Tower[i].Recp_Tower);
	}*/
}