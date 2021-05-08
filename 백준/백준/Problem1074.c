#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long count = 0;

void Problem1074_recursive(long long row, long long col, long long size)
{
	long long row_cos, col_cos, div;
	long long standard;

	if (size == 1)
	{
		count = count + row * 2 + col;
		return;
	}

	div = (long long)pow((double)4, (double)(size - 1));
	standard = (long long)pow((double)2, (double)(size - 1));

	row_cos = row / standard;
	col_cos = col / standard;

	row = row - (row_cos * standard);
	col = col - (col_cos * standard);

	if (row_cos == 0 && col_cos == 0)
	{
		Problem1074_recursive(row, col, size - 1);
	}
	else if (row_cos == 0 && col_cos == 1)
	{
		count = count + div * 1;
		Problem1074_recursive(row, col, size - 1);
	}
	else if (row_cos == 1 && col_cos == 0)
	{
		count = count + div * 2;
		Problem1074_recursive(row, col, size - 1);
	}
	else if (row_cos == 1 && col_cos == 1)
	{
		count = count + div * 3;
		Problem1074_recursive(row, col, size - 1);
	}
}

int Problem1074()
{
	long long row, col, N;

	scanf("%lld%lld%lld", &N, &row, &col);

	Problem1074_recursive(row, col, N);

	printf("%lld\n", count);
}