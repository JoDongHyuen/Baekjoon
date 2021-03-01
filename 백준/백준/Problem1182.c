#include <stdio.h>

int arr[20];
int Used_Check[20] = { 0 };
int count = 0;
void Problem1182_Backtracking(int depth, int target, int value, int sum)
{
	int i;

	if (sum == target)
		count++;
	//여기 else 넣은게 문제였음 target을 찾았다고 다음 선택을 안하는게 아님
	for (i = value; i < depth; i++)
	{
		if (Used_Check[i] == 0)
		{
			Used_Check[i] = 1;
			Problem1182_Backtracking(depth, target, i, sum + arr[i]);
			Used_Check[i] = 0;
		}
	}
}

void Problem1182_Sort(int start, int end)
{
	int low = start, high = end;
	int temp, pivot = arr[(start + end) / 2];

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
		Problem1182_Sort(start, low - 1);
	if (low < end)
		Problem1182_Sort(low, end);
}

int Problem1182()
{
	int Input_Num, Target;
	int i;

	scanf("%d%d", &Input_Num, &Target);

	for (i = 0; i < Input_Num; i++)
		scanf("%d", &arr[i]);

	/* 정렬 파트 */
	Problem1182_Sort(0, Input_Num - 1);

	/* 백트래킹 파트 */
	//Problem1182_Backtracking(Input_Num, Target, 0, 0); 처음에 이렇게 코딩했다가 틀림, 반례 Target이 0인 경우
	for (i = 0; i < Input_Num; i++)
	{
		Used_Check[i] = 1;
		Problem1182_Backtracking(Input_Num, Target, i, arr[i]);
		Used_Check[i] = 1;
	}

	/* 출력 파트 */
	printf("%d\n", count);
}