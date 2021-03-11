#include <stdio.h>

typedef struct _Meeting {
	int start;
	int end;
}Meeting;

Meeting Schedule[100000];
Meeting temp[100000];

void Problem1931_StartSort(int start, int mid, int end)
{
	int main_idx = start, idx1 = start, idx2 = mid;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = Schedule[i];

	while (idx1 <= (mid - 1) && idx2 <= end) {
		if (temp[idx1].start <= temp[idx2].start)
			Schedule[main_idx++] = temp[idx1++];
		else
			Schedule[main_idx++] = temp[idx2++];
	}

	if (idx1 < mid)
		for (i = 0; i < mid - idx1; i++)
			Schedule[main_idx + i] = temp[idx1 + i];
}

void Problem1931_EndSort(int start, int mid, int end)
{
	int main_idx = start, idx1 = start, idx2 = mid;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = Schedule[i];

	while (idx1 <= (mid - 1) && idx2 <= end) {
		if (temp[idx1].end <= temp[idx2].end)
			Schedule[main_idx++] = temp[idx1++];
		else
			Schedule[main_idx++] = temp[idx2++];
	}

	if (idx1 < mid)
		for (i = 0; i < mid - idx1; i++)
			Schedule[main_idx + i] = temp[idx1 + i];
}

void Problem1931_Merge(int start, int end, int flag)
{
	int mid = (start + end) / 2;
	if (start < end)
	{
		Problem1931_Merge(start, mid, flag);
		Problem1931_Merge(mid + 1, end, flag);
		if (flag == 0)
			Problem1931_EndSort(start, mid + 1, end);
		if (flag == 1)
			Problem1931_StartSort(start, mid + 1, end);
	}
}

int Problem1931_Greedy(int Meeting_Num)
{
	int i, end_time = Schedule[0].end;
	int count = 1;

	for (i = 1; i < Meeting_Num; i++)
	{
		if (Schedule[i].start >= end_time && Schedule[i].end >= end_time)
			count++, end_time = Schedule[i].end;
	}
	return count;
}

int Problem1931()
{
	int Meeting_Num, result;
	int i, low = 0, high = 0;

	scanf("%d", &Meeting_Num);

	for (i = 0; i < Meeting_Num; i++)
		scanf("%d %d", &Schedule[i].start, &Schedule[i].end);

	/* 정렬 부분 */
	Problem1931_Merge(0, Meeting_Num - 1, 0);
	
	while (1)
	{
		if (Schedule[high].end != Schedule[high + 1].end)
		{
			Problem1931_Merge(low, high, 1);
			high++;
			low = high;
		}
		else
			high++;

		if (high == (Meeting_Num - 1))
		{
			Problem1931_Merge(low, high, 1);
			break;
		}
	}

	/* 그리디 */
	result = Problem1931_Greedy(Meeting_Num);

	printf("%d\n", result);
}