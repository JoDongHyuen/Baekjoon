#include <stdio.h>

int Heap[200001] = { 0 };
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

	if (HeapSize == 0) {
		printf("%d\n", 0);
	}
	else {
		/* Heap의 Root node pop, leaf node -> root node*/
		printf("%d\n", Heap[1]);
		Heap[1] = Heap[HeapSize];
		Heap[HeapSize] = 0;
		HeapSize--;

		/* Root에서부터 child를 비교해가며 Mas Heap에 맞게 조정*/
		parent = 1;
		while (parent <= HeapSize)
		{
			child_left = parent * 2;
			child_right = parent * 2 + 1;

			if (Heap[parent] < Heap[child_left] && Heap[child_left] >= Heap[child_right])
			{
				swap(parent, child_left);
				parent = child_left;
			}
			else if (Heap[parent] < Heap[child_right] && Heap[child_left] <= Heap[child_right])
			{
				swap(parent, child_right);
				parent = child_right;
			}
			else
				break;
		}
	}
}

void push(int input)
{
	int parent, child;

	if (HeapSize == 0)
		Heap[++HeapSize] = input;
	else
	{
		Heap[++HeapSize] = input;
		child = HeapSize;

		/* leaf node 삽입 후 Max Heap에 맞게 조정*/
		while (child != 1)
		{
			parent = child / 2;
			if (Heap[child] > Heap[parent])
				swap(child, parent);
			else
				break;
			child /= 2;
		}
	}
}

int Problem11279()
{
	int Test_Case;
	int i, input;

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