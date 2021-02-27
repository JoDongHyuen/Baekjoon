#include <stdio.h>

int arr[8] = { 0 };
int Number_Flag[8];
int temp[8];

int Problem15666_Backtracking(int depth, int width, int pos, int value)
{
	// �ߺ� ����� �Ÿ��� ���� Prev_Num
	// �ߺ� ���ڸ� ����ϱ� ���� Used_Check �迭�� ��� �� ��
	int i;
	int Prev_Num = 0;
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (i = value; i < depth; i++)
		{
			if (Prev_Num != Number_Flag[i]) {
				arr[pos] = Number_Flag[i];
				Prev_Num = Number_Flag[i];
				Problem15666_Backtracking(depth, width, pos + 1, i);
			}
		}
	}
}

int Problem15666_Sort(int start, int mid, int end)
{
	int Main_Idx = start, Idx1 = start, Idx2 = mid;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = Number_Flag[i];

	while (Idx1 <= (mid - 1) && Idx2 <= end)
	{
		if (temp[Idx1] <= temp[Idx2])
			Number_Flag[Main_Idx++] = temp[Idx1++];
		else
			Number_Flag[Main_Idx++] = temp[Idx2++];
	}

	if (Idx1 < mid)
		for (i = 0; i < mid - Idx1; i++)
			Number_Flag[Main_Idx + i] = temp[Idx1 + i];
}

int Problem15666_Merge(int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		Problem15666_Merge(start, mid);
		Problem15666_Merge(mid + 1, end);
		Problem15666_Sort(start, mid + 1, end);
	}
}

int Problem15666()
{
	int input_N, input_M;
	int i;

	scanf("%d%d", &input_N, &input_M);
	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* ���� ��Ʈ */
	Problem15666_Merge(0, input_N - 1);

	/* ��Ʈ��ŷ ��Ʈ */
	Problem15666_Backtracking(input_N, input_M, 0, 0);
}