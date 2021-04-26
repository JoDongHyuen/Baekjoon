#include <stdio.h>
#include <stdlib.h>

typedef struct _Position {
	int num;
	int count;
}Position;

Position queue[200001];
int visit[100001];
int front = 0;
int rear = 0;
int result;

void push(int number, int count)
{
	queue[rear].num = number;
	queue[rear].count = count;
	rear++;
}

Position pop()
{
	Position temp = queue[front];
	front++;

	return temp;
}

int Problem1697_BFS(int start, int target)
{
	push(start, 0);
	while (1)
	{
		Position now_pos = pop();
		visit[start] = 1;
		if (now_pos.num == target)
			return now_pos.count;
		else
		{
			if (now_pos.num * 2 < 200000 && visit[now_pos.num * 2] == 0)
			{
				push(now_pos.num * 2, now_pos.count + 1);
				visit[now_pos.num * 2] = 1;
			}
			if (now_pos.num >= 1 && visit[now_pos.num - 1] == 0)
			{
				push(now_pos.num - 1, now_pos.count + 1);
				visit[now_pos.num - 1] = 1;
			}
			if (now_pos.num + 1 <= 200000 && visit[now_pos.num + 1] == 0)
			{
				push(now_pos.num + 1, now_pos.count + 1);
				visit[now_pos.num + 1] = 1;
			}
		}
	}
}

int Problem1697()
{
	int N, K;
	int i, result = 0, count_k;
	scanf("%d %d", &N, &K);

	if (N < K)
		result = Problem1697_BFS(N, K);
	else
		result = N - K;

	printf("%d\n", result);
}