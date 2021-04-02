#include <stdio.h>

int board[502][502] = { 0 };
int vis[502][502] = { 0 };
int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0 ,1, 0, -1 };

typedef struct _cordi
{
	int x;
	int y;
}cordi;

cordi queue[250001] = { 0 };
int front = 0;
int rear = 0;
int result_max = 0;
int area;
int N, M;

void pop()
{
	front++;
}

void push(int x, int y)
{
	queue[rear].x = x;
	queue[rear].y = y;
	vis[x][y] = 1;
	rear++;
}

void BFS()
{
	area = 1;
	while (front != rear)
	{
		int i;
		int move_x, move_y;

		for (i = 0; i < 4; i++)
		{
			move_x = queue[front].x + dx[i];
			move_y = queue[front].y + dy[i];
			if (move_x < 0 || move_y < 0 || move_x >= N || move_y >= M) continue;
			if (board[move_x][move_y] != 1 || vis[move_x][move_y] != 0) continue;
			push(move_x, move_y);
			vis[move_x][move_y] = 1;
			area++;
		}
		pop();
	}

	if (area > result_max)
		result_max = area;
}

int Problem1926()
{
	int count = 0;
	int x, y;

	/* 입력 파트 */
	scanf("%d%d", &N, &M);
	for (x = 0; x < N; x++)
		for (y = 0; y < M; y++)
			scanf("%d", &board[x][y]);

	/* 연산 파트 */
	for (x = 0; x < N; x++)
		for (y = 0; y < M; y++)
		{
			if (board[x][y] == 1 && vis[x][y] == 0)
			{
				count++;
				push(x, y);
				BFS();
			}
		}

	/* 결과 출력 */
	printf("%d\n%d\n", count, result_max);
}