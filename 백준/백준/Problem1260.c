#include <stdio.h>

int graph[1001][1001] = { 0 };
int vis[1001] = { 0 };
int vis2[1001] = { 0 };
int queue[1001];
int stack[1001];
int top = -1;
int front = 0;
int rear = 0;
int N, M, start;

void stack_push(int vertex)
{
	stack[++top] = vertex;
}

int stack_pop()
{
	return stack[top--];
}

int queue_pop()
{
	return queue[front++];
}

void queue_push(int vertex)
{
	queue[rear++] = vertex;
}

void DFS()
{
	while (top != -1)
	{
		int edge = stack_pop();
		printf("%d ", edge);
		int i;
		for (i = 1; i <= N; i++)
			if (vis[i] == 0 && graph[edge][i] == 1) {
				stack_push(i);
				vis[i] = 1;
				DFS();
			}

	}
}

void BFS()
{
	while(front != rear)
	{
		int edge = queue_pop();
		printf("%d ", edge);
		int i;
		for (i = 1; i <= N; i++)
			if (vis2[i] == 0 && graph[edge][i] == 1) {
				queue_push(i);
				vis2[i] = 1;
			}
	}
}

int Problem1260()
{
	int i;
	int x, y;
	scanf("%d%d%d", &N, &M, &start);
	
	for (i = 0; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	stack_push(start);
	vis[start] = 1;
	queue_push(start);
	vis2[start] = 1;

	DFS();
	printf("\n");
	BFS();

}