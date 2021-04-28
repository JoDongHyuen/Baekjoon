#include <stdio.h>
#include <stdlib.h>


typedef struct _cordi {
	int row;
	int col;
}cordi;

int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int map[51][51];
int visit[51][51];
int w, h;
int count;
int front = 0, rear = 0;
cordi queue[101];

void push(int row, int col)
{
	queue[rear].row = row;
	queue[rear].col = col;
	rear++;
}

cordi pop()
{
	cordi temp = queue[front];
	front++;

	return temp;
}

void Problem4963_BFS(int row, int col)
{
	cordi temp;
	int i;
	int change_row, change_col;

	front = 0;
	rear = 0;

	push(row, col);
	visit[row][col] = 1;

	while (front != rear)
	{
		temp = pop();
		for (i = 0; i < 8; i++) {
			change_row = temp.row + dx[i];
			change_col = temp.col + dy[i];
			if (change_row < 0 || change_col < 0 || change_row >= h || change_col >= w) continue;
			if (map[change_row][change_col] == 0 || visit[change_row][change_col] == 1) continue;
			push(change_row, change_col);
			visit[change_row][change_col] = 1;
		}
	}
}

int Problem4963()
{
	int i, j;
	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		else
		{
			count = 0;
			for (i = 0; i < h; i++)
				for (j = 0; j < w; j++) {
					scanf("%d", &map[i][j]);
					visit[i][j] = 0;
				}

			for (i = 0; i < h; i++)
				for (j = 0; j < w; j++) {
					if (map[i][j] == 1 && visit[i][j] == 0)
					{
						count++;
						Problem4963_BFS(i, j);
					}
				}
			
			printf("%d\n", count);
		}
	}
}