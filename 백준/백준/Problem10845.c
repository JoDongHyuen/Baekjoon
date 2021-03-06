#include <stdio.h>
#include <string.h>

int queue[10001];
int head = 0;
int rear = 0;

void push(int num)
{
	queue[rear++] = num;
}

void pop()
{
	if (head == rear)
		printf("%d\n", -1);
	else
		printf("%d\n", queue[head++]);
}

void empty()
{
	if (head == rear)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
}

void size()
{
	printf("%d\n", rear - head);
}

void front()
{
	if (head == rear)
		printf("%d\n", -1);
	else
		printf("%d\n", queue[head]);
}

void back()
{
	if (head == rear)
		printf("%d\n", -1);
	else
		printf("%d\n", queue[rear - 1]);
}

int Problem10845()
{
	int Ist_Num;
	char Ist[6];
	int i, value;
	scanf("%d", &Ist_Num);

	for (i = 0; i < Ist_Num; i++)
	{
		scanf("%s", Ist);
		if (strcmp(Ist, "push") == 0)
		{
			scanf("%d", &value);
			push(value);
		}
		else if (strcmp(Ist, "pop") == 0)
			pop();
		else if (strcmp(Ist, "front") == 0)
			front();
		else if (strcmp(Ist, "back") == 0)
			back();
		else if (strcmp(Ist, "size") == 0)
			size();
		else if (strcmp(Ist, "empty") == 0)
			empty();
	}
}