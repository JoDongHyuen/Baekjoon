#include <stdio.h>

int land[50][50];
int N, M, cabbage;

void Problem1012_Backtracking(int row, int col)
{
	if (row < 0 || row >= N || col < 0 || col >= M)
		return;
	else if (land[row][col] == 0)
		return;
	else
	{
		land[row][col] = 0;
		Problem1012_Backtracking(row + 1, col);
		Problem1012_Backtracking(row - 1, col);
		Problem1012_Backtracking(row, col + 1);
		Problem1012_Backtracking(row, col - 1);
	}
}

int Problem1012()
{
	int Test_Case;
	int i, j, k;
	int row, col, count;

	scanf("%d", &Test_Case);
	for (k = 0; k < Test_Case; k++)
	{
		count = 0;

		scanf("%d %d %d", &M, &N, &cabbage);

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				land[i][j] = 0;

		for (i = 0; i < cabbage; i++) {
			scanf("%d %d", &col, &row);
			land[row][col] = 1;
		}

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++) {
				if (land[i][j] == 1) {
					Problem1012_Backtracking(i, j);
					count++;
				}
			}

		printf("%d\n", count);
	}
}