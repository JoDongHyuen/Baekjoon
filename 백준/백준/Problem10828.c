#include <stdio.h>
#include <string.h>

int stack[10001];
int pos = -1;

void push(int num)
{
	stack[++pos] = num;
}

int pop()
{
	if (pos == -1)
		return pos;
	else
		return stack[pos--];
}

int top()
{
	if (pos == -1)
		return pos;
	else
		return stack[pos];
}

int size()
{
	return pos + 1;
}

int empty()
{
	if (pos == -1)
		return 1;
	else
		return 0;
}

int Problem10828()
{
	int Test_Case, i, input;
	char command[6];

	scanf("%d", &Test_Case);

	for (i = 0; i < Test_Case; i++)
	{
		scanf("%s", command);

		if (strcmp(command, "push") == 0) {
			scanf("%d", &input);
			push(input);
		}

		if (strcmp(command, "top") == 0) {
			printf("%d\n", top());
		}

		if (strcmp(command, "pop") == 0) {
			printf("%d\n", pop());
		}

		if (strcmp(command, "size") == 0) {
			printf("%d\n", size());
		}

		if (strcmp(command, "empty") == 0) {
			printf("%d\n", empty());
		}
	}
}