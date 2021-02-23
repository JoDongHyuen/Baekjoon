#include <stdio.h>
#include <stdlib.h>

/* N - Queen ���� ���ٹ�*/
// 1. ��Ʈ��ŷ ����̴�
// 2. Q�� �ξ��� �� ���忡 ��ŷ
// 2-2. But ��ŷ�� ���� �� ������ ���� �ߴ� ��ŷ���� �ƴ��� 0, 1�� ���� �� �� ����
// 3. �ߺ��� �ع��� �ɷ����� Ȯ�� - ������� �ϸ� �ùٸ� ������ ����

/* N - Queen ����ȭ ���*/
// 1. ���� �� �� �� �࿡ �� �ϳ��� �� �� �ִٴ°� for���� �����ߴ°�?
// 2. ���忡 ��ŷ�� �� Ȥ�� while������ �밢, �����¿츦 ó������ �ʾҴ°�?
// + 9663 �� ������ 1���� �ذ��ϸ� �ð��ʰ��� �ȶ߱� ��

int Problem9663_SetQueen(int row, int col, int Chess_Borad[][14], int depth, int Q_Num)
{
	int local_row, local_col;

	/* �밢�� ó�� */
	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[local_row][local_col] = Q_Num;
		local_row++;
		local_col++;
		if (local_row >= depth || local_col >= depth)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[local_row][local_col] = Q_Num;
		local_row--;
		local_col--;
		if (local_row <= -1 || local_col <= -1)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[local_row][local_col] = Q_Num;
		local_row++;
		local_col--;
		if (local_row >= depth || local_col <= -1)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[local_row][local_col] = Q_Num;
		local_row--;
		local_col++;
		if (local_row <= -1 || local_col >= depth)
			break;
	}

	/* ���� ���� ó�� */
	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[row][local_col] = Q_Num;
		local_col++;
		if (local_col >= depth)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[row][local_col] = Q_Num;
		local_col--;
		if (local_col <= -1)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[local_row][col] = Q_Num;
		local_row++;
		if (local_row >= depth)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == 0)
			Chess_Borad[local_row][col] = Q_Num;
		local_row--;
		if (local_row <= -1)
			break;
	}
}

int Problem9663_UnsetQueen(int row, int col, int Chess_Borad[][14], int depth, int Q_Num)
{
	int local_row, local_col;

	/* �밢�� ó�� */
	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[local_row][local_col] = 0;
		local_row++;
		local_col++;
		if (local_row >= depth || local_col >= depth)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[local_row][local_col] = 0;
		local_row--;
		local_col--;
		if (local_row <= -1 || local_col <= -1)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[local_row][local_col] = 0;
		local_row++;
		local_col--;
		if (local_row >= depth || local_col <= -1)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[local_row][local_col] = 0;
		local_row--;
		local_col++;
		if (local_row <= -1 || local_col >= depth)
			break;
	}

	/* ���� ���� ó�� */
	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[row][local_col] = 0;
		local_col++;
		if (local_col >= depth)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[row][local_col] = 0;
		local_col--;
		if (local_col <= -1)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[local_row][col] = 0;
		local_row++;
		if (local_row >= depth)
			break;
	}

	local_row = row;
	local_col = col;
	while (1)
	{
		if (Chess_Borad[local_row][local_col] == Q_Num)
			Chess_Borad[local_row][col] = 0;
		local_row--;
		if (local_row <= -1)
			break;
	}
}

int Problem9663_Backtracking(int Q_Count, int depth, int* Success_Count, int Chess_Borad[][14], int pos)
{
	int i, j;

	/* N_Queen ������ ī��Ʈ */
	if (Q_Count == depth)
		(*Success_Count)++;
	/* ��� ��Ʈ */
	else
	{
		for (i = depth * Q_Count; i < depth * (Q_Count + 1); i++) // !!���� �� �࿡ �� ���� �� �� �ִٴ°� ����Ʈ�̴�!!
			if (Chess_Borad[i / depth][i % depth] == 0)
			{
				Problem9663_SetQueen(i / depth, i % depth, Chess_Borad, depth, Q_Count + 1);
				Problem9663_Backtracking(Q_Count + 1, depth, Success_Count, Chess_Borad, i);
				Problem9663_UnsetQueen(i / depth, i % depth, Chess_Borad, depth, Q_Count + 1);
			}
	}
}

int Problem9663()
{
	int input;
	int Q_Count = 0, Success_Count = 0;
	int Chess_Borad[14][14] = { 0 };
	int Check_Pos[14][14] = { 0 };

	scanf("%d", &input);

	/* ��Ʈ��ŷ ��Ʈ */
	Problem9663_Backtracking(Q_Count, input, &Success_Count, Chess_Borad, 0);

	/* ��� ��� */
	printf("%d\n", Success_Count);
}

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
	
	/* �Է� ��Ʈ */
	scanf("%d%d", &input_N, &input_M);
	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* ���� ��Ʈ */
	Problem15665_Sort(0, input_N - 1, Number_Flag);

	/* ��Ʈ��ŷ ��Ʈ */
	Problem15665_Backtracking(input_N, input_M, pos, arr, Number_Flag);
}

void Problem15664_Backtracking(int depth, int width, int pos, int value, int arr[], int Used_Check[], int Number_Flag[])
{
	int i;
	int Prev_Num = 0;
	/* ��� ��Ʈ */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	/* ��� ��Ʈ */
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

	/* ���� ��Ʈ */
	Problem15664_Sort(0, input_N - 1, Number_Flag);

	/* ��Ʈ��ŷ ��Ʈ */
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
			if (Used_Check[i] == 0 && Prev_Num != Number_Flag[i]) // Prev_Num ��� arr[pos] ������ 3 3 ~ 3 4 3 �ݷʰ� ����, �̸��� Prev_Num�� 3���� �ʱ�ȭ�Ѵٴ� �Ͱ� ����� ����
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

	/* �Է� ��Ʈ */
	scanf("%d%d", &input_N, &input_M);
	for (i = 0; i < input_N; i++)
		scanf("%d", &Number_Flag[i]);

	/* ���� ��Ʈ */
	Problem15663_Sort(0, input_N - 1, Number_Flag);

	/* ��Ʈ��ŷ ��Ʈ */
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

	/* ���� ��Ʈ */
	Problem15657_Merge(0, input_N - 1, Number_Flag, temp);

	/* ��Ʈ��ŷ ��Ʈ */
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

	/* ���� ��Ʈ */
	Problem15656_Merge(0, input_N - 1, Number_Flag, temp);

	/* ��Ʈ��ŷ ��Ʈ */
	Problem15656_Backtracking(input_N, input_M, pos, arr, Number_Flag);
}

int Problem15655_backtracking(int depth, int width, int pos, int value, int arr[], int Used_Check[], int Number_Flag[])
{
	int i;

	/* ��� ��Ʈ */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	/* ��� ��Ʈ */
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

	/* ���� */
	Problem15655_sort(0, input_N - 1, Number_Flag);
	/* ��Ʈ��ŷ */
	Problem15655_backtracking(input_N, input_M, pos, 0, arr, Used_Check, Number_Flag);
}

int Problem15654_backtracking(int depth, int width, int pos, int arr[], int Used_Check[], int Number_Flag[])
{
	int i;

	/* ��� ��Ʈ */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	/* ��� ��Ʈ */
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

	/* ���� */
	Problem15654_sort(0, input_N - 1, Number_Flag);
	/* ��Ʈ��ŷ */
	Problem15654_backtracking(input_N, input_M, pos, arr, Used_Check, Number_Flag);
}

void Problem4_Tracking(int depth, int width, int pos, int num, int arr[])
{
	int i;
	/* ��� ��Ʈ */
	if (pos == width)
	{
		for (i = 0; i < width; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	/* ��� ��Ʈ */
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