#include <stdio.h>
#include <stdlib.h>

void Problem3_Tracking(int depth, int width, int pos, int arr[])
{
	int i;
	/* ��� ��Ʈ */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	/* ��� ��Ʈ */
	else
	{
		for (i = 0; i < depth; i++) // i < width�� �ߴٰ� �� �� Ʋ��
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
	/* ��� ��Ʈ */
	if (pos == width)
	{
		//�����ϰ� �̷��� ��¿��� �Ÿ��� �ȵ�!
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
	/* ��� ��Ʈ */
	else
	{
		for (i = num; i < depth; i++) // i �����ϴ� �κ��� ����� �ٷ�� �������� �ذ� ����
		{
			if (Used_Check[i] == 0)
			{
				arr[pos] = i + 1; // pos++ �̷� ������ pos �� ��ü�� �����Ű�� �ȵ�
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
	/* ��� ��Ʈ */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	/* ��� ��Ʈ */
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