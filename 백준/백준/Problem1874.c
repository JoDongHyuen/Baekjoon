#include <stdio.h>

int Stack[100001];
int Stack_Top = -1;

char Result[200001];
int Result_Idx = 0;

void Problem1874_push(int value)
{
	Stack[++Stack_Top] = value;
}

int Problem1874_pop()
{
	Result[Result_Idx++] = '-';
	Stack_Top--;
}

int Problem1874()
{
	int Test_Case;
	int input, i, j;
	int Num = 1;

	scanf("%d", &Test_Case);

	for (i = 0; i < Test_Case; i++)
	{
		scanf("%d", &input);

		if (Stack_Top == -1 || Stack[Stack_Top] < input)
		{
			for (j = Num; j <= input;)
			{
				Problem1874_push(Num);
				j = ++Num;
				Result[Result_Idx++] = '+';
			}
			Problem1874_pop();
		}
		else if (Stack[Stack_Top] != input)
			break;
		else
			Problem1874_pop();

	}

	if (i == Test_Case)
		for (j = 0; j < Result_Idx; j++)
			printf("%c\n", Result[j]);
	else
		printf("NO\n");
}