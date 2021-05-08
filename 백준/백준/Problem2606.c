#include <stdio.h>



int queue[10001];
int visit[101];
int internet[101][101];
int Com_Num, count;
int front, rear;

void push(int src)
{
	queue[rear++] = src;
}

int pop()
{
	return queue[front++];
}

int BFS()
{
	int src;
	int i;

	push(1);
	visit[1] = 1;

	while (front != rear)
	{
		src = pop();
		for (i = 1; i <= Com_Num; i++)
		{
			if (visit[i] == 1) continue;
			if (internet[src][i] == 0) continue;
			count++;
			visit[i] = 1;
			push(i);
		}
	}
}

int Problem2606()
{
	int Nat_Num;
	int i, row, col;

	scanf("%d", &Com_Num);
	scanf("%d", &Nat_Num);

	for (i = 0; i < Nat_Num; i++) {
		scanf("%d %d", &row, &col);
		internet[row][col] = 1;
		internet[col][row] = 1;
	}

	BFS();

	printf("%d\n", count);

}