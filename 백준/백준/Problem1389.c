#include <stdio.h>
#include <stdlib.h>

typedef struct _withFriend {
	int person;
	int distance;
}Friend;



Friend queue[105];
int front, rear;
int realation[101][101];
int result[101];
int N, M;

void push(int number, int length)
{
	queue[rear].person = number;
	queue[rear].distance = length;
	rear++;
}

Friend pop()
{
	Friend value = queue[front];
	front++;

	return value;
}

void Problem1389_BFS(int me, int visit[])
{
	int i;
	int sum = 0;
	int min;

	push(me, 0);
	visit[me] = 1;
	while (front != rear)
	{
		Friend var = pop();
		for (i = 1; i <= N; i++)
		{
			if (visit[i] == 1) continue;
			if (realation[var.person][i] != 1) continue;
			push(i, var.distance + 1);
			sum += (var.distance + 1);
			visit[i] = 1;
		}
	}
	result[me] = sum;
}

int Problem1389()
{
	int i, A, B;
	int min;

	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		realation[A][B] = 1;
		realation[B][A] = 1;
	}

	for (i = 1; i <= N; i++) {
		int visit[101] = { 0 };
		front = 0, rear = 0;
		Problem1389_BFS(i, visit);
	}

	min = 1;

	for (i = 2; i <= N; i++)
		if (result[i] < result[min])
			min = i;

	printf("%d\n", min);
}