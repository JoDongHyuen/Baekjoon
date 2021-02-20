#include <stdio.h>
#include <stdlib.h>


int Problem15654_backtracking(int depth, int width, int pos, int arr[], int Used_Check[], int Number_Flag[])
{
	int i;

	/* 출력 파트 */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	/* 재귀 파트 */
	else
	{
		for (i = 0; i < depth; i++)
			if (Used_Check[i] == 0)
			{
				arr[pos] = Number_Flag[i];
				Used_Check[i] = 1;
				Problem15654_backtracking(depth, width, pos + 1, arr, Used_Check, Number_Flag);
				Used_Check[i] = 0;
			}
	}
}

int Problem15654_sort(int start, int end, int arr[])
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
		Problem15654_sort(start, low - 1, arr);
	if (low < end)
		Problem15654_sort(low, end, arr);
}

int Problem15654()
{
	int input_N, input_M, pos = 0;
	int i;
	int arr[8] = { 0 }, Used_Check[8] = { 0 }, Number_Flag[8] = { 0 };
	scanf("%d%d", &input_N, &input_M);

	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* 정렬 */
	Problem15654_sort(0, input_N - 1, Number_Flag);
	/* 백트래킹 */
	Problem15654_backtracking(input_N, input_M, pos, arr, Used_Check, Number_Flag);
}

void Problem4_Tracking(int depth, int width, int pos, int num, int arr[])
{
	int i;
	/* 출력 파트 */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	/* 재귀 파트 */
	else
	{
		for (i = num; i < depth; i++)
		{
			arr[pos] = i + 1;
			Problem4_Tracking(depth, width, pos + 1, i, arr);
		}
	}
}

int backtracking_Problem4()
{
	int input_N, input_M, pos = 0;
	int arr[8];

	scanf("%d %d", &input_N, &input_M);

	Problem4_Tracking(input_N, input_M, pos, 0, arr);
}

void Problem3_Tracking(int depth, int width, int pos, int arr[])
{
	int i;
	/* 출력 파트 */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	/* 재귀 파트 */
	else
	{
		for (i = 0; i < depth; i++) // i < width로 했다가 한 번 틀림
		{
			arr[pos] = i + 1;
			Problem3_Tracking(depth, width, pos + 1, arr);
		}
	}
}

int backtracking_Problem3()
{
	int input_N, input_M, pos = 0;
	int arr[7];

	scanf("%d%d", &input_N, &input_M);

	Problem3_Tracking(input_N, input_M, pos, arr);
}


void Problem2_Tracking(int depth, int width, int pos, int num, int Used_Check[], int arr[])
{
	int i, j;
	/* 출력 파트 */
	if (pos == width)
	{
		//무식하게 이렇게 출력에서 거르면 안됨!
		/*
		for (i = 0; i < width - 1; i++)
			if (arr[i] > arr[i + 1])
				return;
				*/
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	/* 재귀 파트 */
	else
	{
		for (i = num; i < depth; i++) // i 지정하는 부분을 충분히 다루면 오름차순 해결 가능
		{
			if (Used_Check[i] == 0)
			{
				arr[pos] = i + 1; // pos++ 이런 식으로 pos 값 자체를 변경시키면 안됨
				Used_Check[i] = 1;
				Problem2_Tracking(depth, width, pos + 1, i, Used_Check, arr);
				Used_Check[i] = 0;
			}
		}
	}
}

int backtracking_Problem2()
{
	int input_N, input_M, pos = 0;
	int Used_Check[8] = { 0 };
	int arr[8] = { 0 };

	scanf("%d%d", &input_N, &input_M);

	Problem2_Tracking(input_N, input_M, pos, 0, Used_Check, arr);
}

void Problem1_Tracking(int depth, int width, int pos, int Used_Check[], int arr[])
{
	int i, j;
	/* 출력 파트 */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	/* 재귀 파트 */
	else
		for (i = 0; i < depth; i++)
		{
			if (Used_Check[i] == 0)
			{
				arr[pos] = i + 1;
				Used_Check[i] = 1;
				Problem1_Tracking(depth, width, pos + 1, Used_Check, arr);
				Used_Check[i] = 0;
			}
		}

}

int backtracking_Problem1()
{
	int input_N, input_M, pos = 0;
	int Used_Check[8] = { 0 };
	int arr[8] = { 0 };

	scanf("%d%d", &input_N, &input_M);

	Problem1_Tracking(input_N, input_M, pos, Used_Check, arr);

}