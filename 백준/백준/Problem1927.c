#include <stdio.h>

int Heap[100001] = { 0 };
int HeapSize = 0;

void swap(int a, int b)
{
	int temp;
	temp = Heap[a];
	Heap[a] = Heap[b];
	Heap[b] = temp;
}

void pop()
{
	int parent, child_left, child_right;

	if (HeapSize == 0)
		printf("%d\n", 0);
	else
	{
		printf("%d\n", Heap[1]);
		Heap[1] = Heap[HeapSize];
		Heap[HeapSize--] = 0;
		parent = 1;
		while (parent * 2 <= HeapSize)
		{
			child_left = parent * 2;
			child_right = parent * 2 + 1;
			/* case 1 */
			if (Heap[child_left] == 0 && Heap[child_right] == 0)
				break;
			/* case 2 */
			else if (Heap[child_left] != 0 && Heap[child_right] == 0)
			{
				if (Heap[parent] > Heap[child_left]) {
					swap(parent, child_left);
					parent = child_left;
				}
				else
					break;
			}
			/* case 3 */
			else if (Heap[child_left] != 0 && Heap[child_right] != 0)
			{
				if (Heap[parent] > Heap[child_left] && Heap[child_left] <= Heap[child_right])
				{
					swap(parent, child_left);
					parent = child_left;
				}
				else if (Heap[parent] > Heap[child_right] && Heap[child_left] > Heap[child_right])
				{
					swap(parent, child_right);
					parent = child_right;
				}
				else
					break;
			}
		}
	}
}

void push(int input)
{
	int child, parent;

	Heap[++HeapSize] = input;
	if (HeapSize != 1)
	{
		child = HeapSize;
		while (child != 1)
		{
			parent = child / 2;
			if (Heap[parent] > Heap[child])
				swap(parent, child);
			child /= 2;
		}
	}
}

int Problem1927()
{
	int Test_Case;
	int input, i;

	scanf("%d", &Test_Case);
	for (i = 0; i < Test_Case; i++)
	{
		scanf("%d", &input);
		if (input == 0)
			pop();
		else
			push(input);
	}
}