#include <stdio.h>

typedef struct _thing {
	int weight;
	int value;
}thing;

thing thing_arr[100];

int Problem12865()
{
	int N, K;
	int i;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
		scanf("%d %d", &thing_arr[i].weight, &thing_arr[i].value);

}