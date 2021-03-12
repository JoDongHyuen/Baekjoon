#include <stdio.h>
#include <limits.h>

int Problem18111()
{
	int map[500][500];
	int N, M;
	int row, col, height, Block_Num, Block_Count;
	int time, result_time = INT_MAX, result_height = 0;

	/* 입력 파트 */
	scanf("%d %d %d", &N, &M, &Block_Num);
	for (row = 0; row < N; row++)
		for (col = 0; col < M; col++)
			scanf("%d", &map[row][col]);

	/* 연산 파트 */
	for (height = 0; height <= 256; height++)
	{
		time = 0;
		Block_Count = Block_Num;
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < M; col++)
			{
				if (map[row][col] == height)
					continue;
				else if (map[row][col] > height)
				{
					time = time + 2 * (map[row][col] - height);
					Block_Count = Block_Count + (map[row][col] - height);
				}
				else
				{
					time = time + (height - map[row][col]);
					Block_Count = Block_Count - (height - map[row][col]);
				}
			}
		}
		if (Block_Count < 0)
			continue;
		if (time <= result_time)
		{
			result_height = height;
			result_time = time;
		}
	}

	/* 출력 파트 */
	printf("%d %d\n", result_time, result_height);
}