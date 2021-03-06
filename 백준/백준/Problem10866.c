#include <stdio.h>
#include <string.h>
#define MX 10000

int queue[MX * 2 + 1];
int front = MX, back = MX;

void push_front(int num)
{
	queue[--front] = num;
}

void push_back(int num)
{
	queue[back++] = num;
}

void pop_front()
{
	if (front == back)
		printf("%d\n", -1);
	else
		printf("%d\n", queue[front++]);
}

void pop_back()
{
	if (front == back)
		printf("%d\n", -1);
	else
		printf("%d\n", queue[--back]);
}

void empty()
{
	if (front == back)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
}

void size()
{
	printf("%d\n", back - front);
}

void front_f()
{
	if (front == back)
		printf("%d\n", -1);
	else
		printf("%d\n", queue[front]);
}

void back_f()
{
	if (front == back)
		printf("%d\n", -1);
	else
		printf("%d\n", queue[back - 1]);
}

int Problem10866()
{
	char Inst[11];
	int Inst_Num;
	int i, value;

	scanf("%d", &Inst_Num);

	for (i = 0; i < Inst_Num; i++)
	{
		scanf("%s", Inst);
		if (strcmp(Inst, "push_front") == 0)
		{
			scanf("%d", &value);
			push_front(value);
		}
		else if (strcmp(Inst, "push_back") == 0)
		{
			scanf("%d", &value);
			push_back(value);
		}
		else if (strcmp(Inst, "pop_front") == 0)
			pop_front();
		else if (strcmp(Inst, "pop_back") == 0)
			pop_back();
		else if (strcmp(Inst, "size") == 0)
			size();
		else if (strcmp(Inst, "empty") == 0)
			empty();
		else if (strcmp(Inst, "front") == 0)
			front_f();
		else if (strcmp(Inst, "back") == 0)
			back_f();
	}
}