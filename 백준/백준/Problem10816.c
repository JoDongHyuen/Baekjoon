#include <stdio.h>

int N[500000];
int low_pos, high_pos;
/*
void Problem10816_BS(int start, int end, int target)
{
	int mid = (start + end) / 2;
	if (start > end)
		return;

	if (target < N[mid])
		Problem10816_BS(start, mid - 1, target);
	else if (N[mid] < target)
		Problem10816_BS(mid + 1, end, target);
	else
	{
		low_pos = MIN(mid, low_pos);
		high_pos = MAX(mid, high_pos);
		Problem10816_BS(start, mid - 1, target);
		Problem10816_BS(mid + 1, end, target);
	}
}*/

int Problem10816_lower(int start, int end, int target)
{
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (N[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int Problem10816_upper(int start, int end, int target)
{
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (N[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

void Problem10816_Sort(int start, int end)
{
	int pivot = N[(start + end) / 2];
	int low = start, high = end;
	int temp;

	while (low <= high)
	{
		while (N[low] < pivot) low++;
		while (pivot < N[high]) high--;
		if (low <= high)
		{
			temp = N[low];
			N[low] = N[high];
			N[high] = temp;
			low++;
			high--;
		}
	}
	if (start < low - 1)
		Problem10816_Sort(start, low - 1);
	if (low < end)
		Problem10816_Sort(low, end);
}

int Problem10816()
{
	int Input_N, Input_M, target, count;
	int i;
	scanf("%d", &Input_N);

	for (i = 0; i < Input_N; i++)
		scanf("%d", &N[i]);

	/* 정렬 부분 */
	Problem10816_Sort(0, Input_N - 1);

	/* 이진 탐색 부분 */
	scanf("%d", &Input_M);
	for (i = 0; i < Input_M; i++)
	{
		scanf("%d", &target);
		low_pos = 500001;
		high_pos = -1;
		low_pos = Problem10816_lower(0, Input_N - 1, target);
		high_pos = Problem10816_upper(0, Input_N - 1, target);

		if (N[high_pos] == target)
			printf("%d ", high_pos - low_pos + 1);
		else
			printf("%d ", high_pos - low_pos);
	}
}