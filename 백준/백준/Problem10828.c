#include <stdio.h>
#include <string.h>

int stack[10001];
int pos = -1;

void Problem10828_push(int num)
{
	stack[++pos] = num;
}

int Problem10828_pop()
{
	if (pos == -1)
		return pos;
	else
		return stack[pos--];
}

int Problem10828_top()
{
	if (pos == -1)
		return pos;
	else
		return stack[pos];
}

int Problem10828_size()
{
	return pos + 1;
}

int Problem10828_empty()
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
			Problem10828_push(input);
		}

		if (strcmp(command, "top") == 0) {
			printf("%d\n", Problem10828_top());
		}

		if (strcmp(command, "pop") == 0) {
			printf("%d\n", Problem10828_pop());
		}

		if (strcmp(command, "size") == 0) {
			printf("%d\n", Problem10828_size());
		}

		if (strcmp(command, "empty") == 0) {
			printf("%d\n", Problem10828_empty());
		}
	}
}