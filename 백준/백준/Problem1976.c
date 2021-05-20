#include <stdio.h>

int city_set[201];

int find(int x)
{
	if (x == city_set[x])
		return x;
	else
		return city_set[x] = find(city_set[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if(x != y)
		if (x < y)city_set[y] = x;
		else city_set[x] = y;
}

int Problem1976()
{
	int N, connect;
	int M, want_visit;
	int i, j, post, now;
	int flag = 1;

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 1; i <= N; i++)
		city_set[i] = i;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			scanf("%d", &connect);
			if (connect == 1)
				Union(i, j);
		}

	scanf("%d", &want_visit);
	post = find(want_visit - 1);
	for (i = 1; i < M; i++)
	{
		scanf("%d", &want_visit);
		now = find(want_visit - 1);
		if (post != now)
		{
			flag = 0;
			break;
		}
	}

	if (flag == 1)
		printf("YES\n");
	else
		printf("NO\n");
}