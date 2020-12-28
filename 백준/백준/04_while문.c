#include <stdio.h>
#include <assert.h>

int WHILEproblem3ver3()
{
	int num, cycle, t, o, c_num;
	cycle = 0;

	scanf("%d", &num);

	c_num = (num % 10) * 10 + (((num / 10) + (num % 10)) % 10);
	cycle++;

	while (c_num != num)
	{
		c_num = (c_num % 10) * 10 + (((c_num / 10) + (c_num % 10)) % 10);
		cycle++;
	}
	printf("%d", cycle);
}

int WHILEproblem3ver2()
{
	int num, cycle, t, o, c_num;
	cycle = 0;

	scanf("%d", &num);

	c_num = num;
	t = c_num / 10;
	o = c_num % 10;
	c_num = t + o;
	c_num = o * 10 + c_num % 10;
	cycle++;

	while (c_num != num)
	{
		t = c_num / 10;
		o = c_num % 10;
		c_num = t + o;
		c_num = o * 10 + c_num % 10;
		cycle++;
	}
	printf("%d", cycle);
}

int WHILEproblem3()
{
	int num, cycle, t, o, c_num, pair;
	cycle = 0;

	scanf("%d", &num);

	if (num < 10)
		num = num * 10;
	c_num = num;
	t = c_num / 10;
	o = c_num % 10;
	c_num = t + o;

	while (1)
	{
		pair = o * 10 + c_num % 10;
		cycle++;
		if (pair == num)
		{
			printf("%d\n", cycle);
			break;
		}
		else
		{
			t = o;
			o = c_num % 10;
			c_num = t + o;
		}

	}
}

int WHILEproblem2()
{
	int i, j;

	while (scanf("%d %d", &i, &j) != EOF)
		printf("%d\n", i + j);
}

int WHILEproblem1()
{
	int i, j, check;

	while (1)
	{
		scanf("%d %d", &i, &j);
		if (i == 0 && j == 0)
			break;
		printf("%d\n", i + j);

	}
}