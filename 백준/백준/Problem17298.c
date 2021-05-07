#include <stdio.h>


int array[1000001];
int stack[1000001];
int top = -1;
int len;

void push(int value)
{
	stack[++top] = value;
}

void pop()
{
	top--;
}

int Problem17298()
{
	int i;
	int num;

	scanf("%d", &len);
	for (i = 0; i < len; i++)
		scanf("%d", &array[i]);

	for (i = len - 1; i >= 0; i--)
	{
		while (1)
		{
			if (top == -1) {
				push(array[i]);
				array[i] = -1;
				break;
			}
			else if (stack[top] > array[i]) {
				num = array[i];
				array[i] = stack[top];
				push(num);
				break;
			}
			else
				pop();
		}
	}

	for (i = 0; i < len; i++)
		printf("%d ", array[i]);
}