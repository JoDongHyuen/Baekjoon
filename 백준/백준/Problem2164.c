#include <stdio.h>

int Card[500001];
int head = 0, rear = -1;
int N;

void push(int Num)
{
	rear = (rear + 1) % N;
	Card[rear] = Num;
}

void pop()
{
	head = (head + 1) % N;
}

int Problem2164()
{
	int i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		push(i + 1);

	while(rear != head) {
		pop();
		push(Card[head]);
		pop();
	}

	printf("%d\n", Card[rear]);
}