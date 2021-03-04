#include <stdio.h>

int Problem1920_Sort(int start, int end, int arr[])
{
	int pivot = arr[(start + end) / 2];
	int low = start, high = end;
	int temp;

	while (low <= high)
	{
		while (arr[low] < pivot) low++;
		while (pivot < arr[high]) high--;
		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			low++;
			high--;
		}
	}
	if (start < low - 1)
		Problem1920_Sort(start, low - 1, arr);
	if (low < end)
		Problem1920_Sort(low, end, arr);
}

void Problem1920_BS(int start, int end, int target, int arr[])
{
	int mid = (start + end) / 2;

	if (start > end) {
		printf("%d\n", 0);
		return;
	}

	if (arr[mid] == target) {
		printf("%d\n", 1);
		return;
	}
	else {
		if (target < arr[mid])
			Problem1920_BS(start, mid - 1, target, arr);
		else
			Problem1920_BS(mid + 1, end, target, arr);
	}
}

int Problem1920()
{
	int N, M, i, target;
	int Nrr[100001];

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &Nrr[i]);

	/* 정렬 호출 */
	Problem1920_Sort(0, N - 1, Nrr);

	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &target);
		/* 이진 탐색 호출 */
		Problem1920_BS(0, N - 1, target, Nrr);
	}
}