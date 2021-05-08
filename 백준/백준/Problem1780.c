#include <stdio.h>

int paper[2187][2187];
int size;
int Paper_0, Paper_Minus_1, Paper_Plus_1;

int Check_Paper(int row, int col, int size)
{
	int i, j;

	for (i = 0; i < size * size - 1; i++)
		if (paper[row + (i / size)][col + (i % size)] != paper[row + ((i + 1) / size)][col + ((i + 1) % size)])
			return 0;
	return 1;
}

void Produce_Paper(int value)
{
	switch (value)
	{
	case -1:
		Paper_Minus_1++;
		break;
	case 0:
		Paper_0++;
		break;
	case 1:
		Paper_Plus_1++;
		break;
	}
}

void Paper_Cut(int row, int col, int size)
{
	int Whether_Cut;

	if (size == 1)
		Produce_Paper(paper[row][col]);
	else
	{
		Whether_Cut = Check_Paper(row, col, size);
		
		if (Whether_Cut == 1)
			Produce_Paper(paper[row][col]);
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Paper_Cut(row + i * size / 3, col + j * size / 3, size / 3);
		}
	}
}

int Problem1780()
{
	int i, j;

	scanf("%d", &size);
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			scanf("%d", &paper[i][j]);

	Paper_Cut(0, 0, size);

	printf("%d\n%d\n%d\n", Paper_Minus_1, Paper_0, Paper_Plus_1);
}