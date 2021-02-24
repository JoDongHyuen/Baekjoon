#include<stdio.h>

typedef struct _stack {
	int Height;
	int Min_Height;
	int Max_Height;
}Stack;

Stack Stack_Tower[500000];
int Problem2943_Stack_Top = -1;

void Problem2943_Push(int value)
{
	Stack_Tower[++Problem2943_Stack_Top].Height = value;
	if (Problem2943_Stack_Top == 0) {
		Stack_Tower[Problem2943_Stack_Top].Max_Height = value;
		Stack_Tower[Problem2943_Stack_Top].Min_Height = value;
	}
	else if (value > Stack_Tower[Problem2943_Stack_Top - 1].Max_Height) {
		Stack_Tower[Problem2943_Stack_Top].Max_Height = value;
		Stack_Tower[Problem2943_Stack_Top].Min_Height = Stack_Tower[Problem2943_Stack_Top - 1].Min_Height;
	}
	
	else if (value < Stack_Tower[Problem2943_Stack_Top - 1].Min_Height) {
		Stack_Tower[Problem2943_Stack_Top].Max_Height = Stack_Tower[Problem2943_Stack_Top - 1].Max_Height;
		Stack_Tower[Problem2943_Stack_Top].Min_Height = value;
	}
	else {
		Stack_Tower[Problem2943_Stack_Top].Max_Height = Stack_Tower[Problem2943_Stack_Top - 1].Max_Height;
		Stack_Tower[Problem2943_Stack_Top].Min_Height = Stack_Tower[Problem2943_Stack_Top - 1].Min_Height;
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

		if (Tower_Height == Stack_Tower[Problem2943_Stack_Top].Max_Height)
			printf("%d ", 0);
		else if (Tower_Height == Stack_Tower[Problem2943_Stack_Top].Min_Height)
			printf("%d ", i);
		else
		{
			count = 0;
			for (j = 0; j < i; j++)
				if (Tower_Height < Stack_Tower[j].Height)
					count++;
			printf("%d ", count);
		}
	}
}