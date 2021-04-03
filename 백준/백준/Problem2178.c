#include <stdio.h>

typedef struct _cordi {
	int x;
	int y;
}cordi;

int vis[100][100] = { 0 };
int map[100][100] = { 0 };
int distance[100][100] = { 0 };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
cordi queue[10001];
int front = 0;
int rear = 0;

void pop()
{
	front++;
}

void push(int x, int y)
{
	queue[rear].x = x;
	queue[rear].y = y;
	rear++;
}

void BFS()
{
	int i;
	while (front != rear)
	{
		for (i = 0; i < 4; i++)
		{
			int move_x = queue[front].x + dx[i];
			int move_y = queue[front].y + dy[i];
			if (move_x < 0 || move_y < 0 || move_x >= N || move_y >= M) continue;
			if (map[move_x][move_y] != 1 || vis[move_x][move_y] != 0) continue;
			push(move_x, move_y);
			vis[move_x][move_y] = 1;
			distance[move_x][move_y] = distance[queue[front].x][queue[front].y] + 1;
		}
		pop();
	}
}

int Problem2178()
{
	int x, y;
	scanf("%d%d", &N, &M);
	for (x = 0; x < N; x++)
		for (y = 0; y < M; y++)
			scanf("%1d", &map[x][y]);

	push(0, 0);
	vis[0][0] = 1;
	distance[0][0] = 1;
	BFS();

	printf("%d\n", distance[N - 1][M - 1]);
}