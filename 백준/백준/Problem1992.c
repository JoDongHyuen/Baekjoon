#include <stdio.h>

int bitmap[65][65];
int size;

int Can_Compression(row, col, size)
{
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			if (bitmap[row][col] != bitmap[row + i][col + j])
				return 0;
	return 1;
}

void Check_Paper(row, col, size)
{
	int mode;

	mode = Can_Compression(row, col, size);

	if (mode == 1)
		printf("%d", bitmap[row][col]);
	else if (mode == 0)
	{
		if (size == 2)
			printf("(%d%d%d%d)", bitmap[row][col], bitmap[row][col + 1], bitmap[row + 1][col], bitmap[row + 1][col + 1]);
		else
		{
			printf("(");
			Check_Paper(row, col, size / 2);
			Check_Paper(row, col + size / 2, size / 2);
			Check_Paper(row + size / 2, col, size / 2);
			Check_Paper(row + size / 2, col + size / 2, size / 2);
			printf(")");
		}
	}
}

int Problem1992()
{
	int i, j;
	scanf("%d", &size);
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			scanf("%1d", &bitmap[i][j]);

	Check_Paper(0, 0, size);
	printf("\n");
}