#include <stdio.h>
#include <stdlib.h>

void Problem15665_Backtracking(int depth, int width, int pos, int arr[], int Number_Flag[])
{
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
		for (i = 0; i < depth; i++)
		{
			if (Prev_Num != Number_Flag[i]) 
			{
				arr[pos] = Number_Flag[i];
				Prev_Num = arr[pos];
				Problem15665_Backtracking(depth, width, pos + 1, arr, Number_Flag);
			}
		}
	}
}

void Problem15665_Sort(int start, int end, int target[])
{
	int pivot = target[(start + end) / 2];
	int low = start, high = end;
	int temp;

	while (low <= high)
	{
		while (target[low] < pivot) low++;
		while (pivot < target[high]) high--;
		if (low <= high)
		{
			temp = target[low];
			target[low] = target[high];
			target[high] = temp;
			low++;
			high--;
		}
	}
	if (start < low - 1)
		Problem15665_Sort(start, low - 1, target);
	if (low < end)
		Problem15665_Sort(low, end, target);
}

int Problem15665()
{
	int input_N, input_M;
	int arr[7], Number_Flag[7];
	int i, pos = 0;
	
	/* 입력 파트 */
	scanf("%d%d", &input_N, &input_M);
	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* 정렬 파트 */
	Problem15665_Sort(0, input_N - 1, Number_Flag);

	/* 백트래킹 파트 */
	Problem15665_Backtracking(input_N, input_M, pos, arr, Number_Flag);
}

void Problem15664_Backtracking(int depth, int width, int pos, int value, int arr[], int Used_Check[], int Number_Flag[])
{
	int i;
	int Prev_Num = 0;
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
		for(i = value; i < depth; i++)
			if (Used_Check[i] == 0 && Prev_Num != Number_Flag[i])
			{
				arr[pos] = Number_Flag[i];
				Prev_Num = arr[pos];
				Used_Check[i] = 1;
				Problem15664_Backtracking(depth, width, pos + 1, i, arr, Used_Check, Number_Flag);
				Used_Check[i] = 0;
			}
	}
}

void Problem15664_Sort(int start, int end, int arr[])
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
		Problem15664_Sort(start, low - 1, arr);
	if (low < end)
		Problem15664_Sort(low, end, arr);
}

int Problem15664()
{
	int input_N, input_M;
	int arr[8], Used_Check[8] = { 0 }, Number_Flag[8];
	int i, pos = 0;

	scanf("%d%d", &input_N, &input_M);

	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* 정렬 파트 */
	Problem15664_Sort(0, input_N - 1, Number_Flag);

	/* 백트래킹 파트 */
	Problem15664_Backtracking(input_N, input_M, pos, 0, arr, Used_Check, Number_Flag);
}

int Problem15663_Bakctracking(int depth, int width, int pos, int arr[], int Number_Flag[], int Used_Check[])
{
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
		for (i = 0; i < depth; i++)
		{
			if (Used_Check[i] == 0 && Prev_Num != Number_Flag[i]) // Prev_Num 대신 arr[pos] 넣으면 3 3 ~ 3 4 3 반례가 존재, 이말은 Prev_Num을 3으로 초기화한다는 것과 비슷한 말임
			{
				arr[pos] = Number_Flag[i];
				Prev_Num = arr[pos];
				Used_Check[i] = 1;
				Problem15663_Bakctracking(depth, width, pos + 1, arr, Number_Flag, Used_Check);
				Used_Check[i] = 0;
			}
		}
	}
}

int Problem15663_Sort(int start, int end, int target[])
{
	int pivot = target[(start + end) / 2];
	int low = start, high = end;
	int temp;

	while (low <= high)
	{
		while (target[low] < pivot) low++;
		while (pivot < target[high]) high--;
		if (low <= high)
		{
			temp = target[low];
			target[low] = target[high];
			target[high] = temp;
			low++;
			high--;
		}
	}
	if (start < low - 1)
		Problem15663_Sort(start, low - 1, target);
	if (low < end)
		Problem15663_Sort(low, end, target);
}

int Problem15663()
{
	int input_N, input_M;
	int Number_Flag[8], arr[8], Used_Check[8] = { 0 };
	int i, pos = 0;

	/* 입력 파트 */
	scanf("%d%d", &input_N, &input_M);
	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* 정렬 파트 */
	Problem15663_Sort(0, input_N - 1, Number_Flag);

	/* 백트래킹 파트 */
	Problem15663_Bakctracking(input_N, input_M, pos, arr, Number_Flag, Used_Check);

}

int Problem15657_Backtracking(int depth, int width, int pos, int num, int arr[], int Number_Flag[])
{
	int i;

	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (i = num; i < depth; i++)
		{
			arr[pos] = Number_Flag[i];
			Problem15657_Backtracking(depth, width, pos + 1, i, arr, Number_Flag);
		}
	}
}

int Problem15657_Sort(int start, int mid, int end, int arr[], int temp[])
{
	int Main_Idx = start, Idx1 = start, Idx2 = mid;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = arr[i];

	while (Idx1 <= mid - 1 && Idx2 <= end)
	{
		if (temp[Idx1] <= temp[Idx2])
			arr[Main_Idx++] = temp[Idx1++];
		else
			arr[Main_Idx++] = temp[Idx2++];
	}

	if (Idx1 < mid)
		for (i = 0; i < mid - Idx1; i++)
			arr[Main_Idx + i] = temp[Idx1 + i];
}

int Problem15657_Merge(int start, int end, int arr[], int temp[])
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Problem15657_Merge(start, mid, arr, temp);
		Problem15657_Merge(mid + 1, end, arr, temp);
		Problem15657_Sort(start, mid + 1, end, arr, temp);
	}
}

int Problem15657()
{
	int Number_Flag[7], temp[7], arr[7];
	int input_N, input_M;
	int i, pos = 0;
	scanf("%d%d", &input_N, &input_M);

	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* 정렬 파트 */
	Problem15657_Merge(0, input_N - 1, Number_Flag, temp);

	/* 백트래킹 파트 */
	Problem15657_Backtracking(input_N, input_M, pos, 0, arr, Number_Flag);
}

int Problem15656_Backtracking(int depth, int width, int pos, int arr[], int Number_Flag[])
{
	int i;

	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (i = 0; i < depth; i++)
		{
			arr[pos] = Number_Flag[i];
			Problem15656_Backtracking(depth, width, pos + 1, arr, Number_Flag);
		}
	}
}

int Problem15656_Sort(int start, int mid, int end, int arr[], int temp[])
{
	int Main_Idx = start, Idx1 = start, Idx2 = mid;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = arr[i];

	while (Idx1 <= mid - 1 && Idx2 <= end)
	{
		if (temp[Idx1] <= temp[Idx2])
			arr[Main_Idx++] = temp[Idx1++];
		else
			arr[Main_Idx++] = temp[Idx2++];
	}

	if (Idx1 < mid)
		for (i = 0; i < mid - Idx1; i++)
			arr[Main_Idx + i] = temp[Idx1 + i];
}

int Problem15656_Merge(int start, int end, int arr[], int temp[])
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Problem15656_Merge(start, mid, arr, temp);
		Problem15656_Merge(mid + 1, end, arr, temp);
		Problem15656_Sort(start, mid + 1, end, arr, temp);
	}
}

int Problem15656()
{
	int Number_Flag[7], temp[7], arr[7];
	int input_N, input_M;
	int i, pos = 0;
	scanf("%d%d", &input_N, &input_M);

	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* 정렬 파트 */
	Problem15656_Merge(0, input_N - 1, Number_Flag, temp);

	/* 백트래킹 파트 */
	Problem15656_Backtracking(input_N, input_M, pos, arr, Number_Flag);
}

int Problem15655_backtracking(int depth, int width, int pos, int value, int arr[], int Used_Check[], int Number_Flag[])
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
		for (i = value; i < depth; i++)
			if (Used_Check[i] == 0)
			{
				arr[pos] = Number_Flag[i];
				Used_Check[i] = 1;
				Problem15655_backtracking(depth, width, pos + 1, i, arr, Used_Check, Number_Flag);
				Used_Check[i] = 0;
			}
	}
}

int Problem15655_sort(int start, int end, int arr[])
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
		Problem15655_sort(start, low - 1, arr);
	if (low < end)
		Problem15655_sort(low, end, arr);
}

int Problem15655()
{
	int input_N, input_M, pos = 0;
	int i;
	int arr[8] = { 0 }, Used_Check[8] = { 0 }, Number_Flag[8] = { 0 };
	scanf("%d%d", &input_N, &input_M);

	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* 정렬 */
	Problem15655_sort(0, input_N - 1, Number_Flag);
	/* 백트래킹 */
	Problem15655_backtracking(input_N, input_M, pos, 0, arr, Used_Check, Number_Flag);
}

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