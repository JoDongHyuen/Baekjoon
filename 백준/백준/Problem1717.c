#include <stdio.h>

int parent[1000001];

int find(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y)
		if (x < y)parent[y] = x;
		else parent[x] = y;
}

void isSameParent(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		printf("YES\n");
	else
		printf("NO\n");
}

int Problem1717()
{
	int element_num, ist_num;
	int ist_check, x, y;

	scanf("%d%d", &element_num, &ist_num);

	for (int i = 1; i <= element_num; i++)
		parent[i] = i;

	for (int i = 0; i < ist_num; i++)
	{
		scanf("%d%d%d", &ist_check, &x, &y);
		if (ist_check == 0)
			union_set(x, y);
		else
			isSameParent(x, y);
	}
}