#include <stdio.h>
#include <stdlib.h>

void Problem2_Tracking(int depth, int width, int pos, int num, int Used_Check[], int arr[])
{
	int i, j;

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
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
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