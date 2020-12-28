#include <stdio.h>
#include <assert.h>

int FORproblem11()
{
	int num, a, x, i;
	scanf("%d %d", &num, &x);

	for (i = 1; i <= num; i++)
	{
		scanf("%d", &a);
		if (a < x)
			printf("%d ", a);
	}
}

int FORproblem10()
{
	int i, j, num;
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num - i; j++)
			printf(" ");
		for (; j <= num; j++)
			printf("*");
		printf("\n");
	}
}

int FORproblem9()
{
	int i, j, num;
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
}

int FORproblem8()
{
	int num, i, a, b;
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}
}

int FORproblem7()
{
	int num, i, a, b;
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}
}

int FORproblem6()
{
	int num, i;
	scanf("%d", &num);

	for (i = 0; num >= 1; num--)
		printf("%d\n", num);
}


int FORproblem5()
{
	int num, i;
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
		printf("%d\n", i);
}

int FORproblem4()
{
	int num, i, a, b;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

}

int assertTEST()
{
	int num;

	while (1)
	{
		scanf("%d", &num);
		assert(num >= 0);

		printf("OK\n");
	}
}

int FORproblem3()
{
	int sum, i, repeat;
	sum = 0;

	scanf("%d", &repeat);

	for (i = 1; i <= repeat; i++)
		sum = sum + i;
	
	printf("%d", sum);
}

int FORproblem3ver2()
{
	int i, sum;
	
	scanf("%d", &i);

	sum = i * (i + 1) / 2;

	printf("%d", sum);
}

int FORproblem2()
{
	int repeat, a, b, i;
	
	scanf("%d", &repeat);

	for (i = 0; i < repeat; i++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", a + b);
	}
}


int FORproblem1()
{
	int i,num;

	scanf("%d", &num);

	for (i = 1; i < 10; i++)
		printf("%d * %d = %d\n", num, i, num*i);
}