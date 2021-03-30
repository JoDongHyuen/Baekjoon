#include <stdio.h>

int Heap[200001] = { 0 };
int count = 0;
int pos = 1;

void swap(int a, int b)
{
	int temp;

	temp = Heap[a];
	Heap[a] = Heap[b];
	Heap[b] = temp;
}

int Problem11279()
{
	int Test_Case;
	int i, input;
	int temp;

	scanf("%d", &Test_Case);

	for (i = 0; i < Test_Case; i++)
	{
		scanf("%d", &input);
		if (input == 0)
		{
			if (count == 0) {
				printf("%d\n", 0);
			}
			else {
				printf("%d\n", Heap[1]);
				Heap[1] = Heap[count];
				Heap[count] = 0;
				temp = 1;
				while (temp <= count)
				{
					if (Heap[temp] < Heap[temp * 2] && Heap[temp * 2] >= Heap[temp * 2 + 1])
					{
						swap(temp, temp * 2);
						temp = temp * 2;
					}
					else if (Heap[temp] < Heap[temp * 2 + 1] && Heap[temp * 2] <= Heap[temp * 2 + 1])
					{
						swap(temp, temp * 2 + 1);
						temp = temp * 2 + 1;
					}
					else
						break;
				}
				count--;
			}
		}
		else
		{
			if (count == 0)
				Heap[1] = input;
			else
			{
				while (1) {
 					if (Heap[pos * 2] == 0) {
						Heap[pos * 2] = input;
						temp = pos * 2;
						break;
					}
					else if (Heap[pos * 2 + 1] == 0) {
						Heap[pos * 2 + 1] = input;
						temp = pos * 2 + 1;
						break;
					}
					else
						pos++;
				}

				while (temp != 1)
				{
					if (Heap[temp] > Heap[temp / 2])
						swap(temp, temp / 2);
					else
						break;
					temp /= 2;
				}
			}
			count++;
		}
	}
}