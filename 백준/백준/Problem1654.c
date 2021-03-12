#include <stdio.h>

long long Lan_Arr[10001] = { 0 };
long long temp[10001] = { 0 };
long long result = 0;

void Problem1654_BS(long long start, long long end, long long target, long long num)
{
	long long count = 0;
	long long i;
	long long mid = (start + end) / 2;

	if (start > end)
		return;

	for (i = 1; i <= num; i++)
		count = count + (Lan_Arr[i] / mid);

	if (count >= target && mid > result)
		result = mid;

	if (count >= target)
		Problem1654_BS(mid + 1, end, target, num);
 	else
		Problem1654_BS(start, mid - 1, target, num);

}

void Problem1654_Sort(long long start, long long mid, long long end)
{
	long long main_idx, idx1, idx2;
	long long i;

	main_idx = start, idx1 = start, idx2 = mid;

	for (i = start; i <= end; i++)
		temp[i] = Lan_Arr[i];

	while (idx1 <= (mid - 1) && idx2 <= end)
	{
		if (temp[idx1] <= temp[idx2])
			Lan_Arr[main_idx++] = temp[idx1++];
		else
			Lan_Arr[main_idx++] = temp[idx2++];
	}
	if (idx1 < mid)
		for (i = 0; i < mid - idx1; i++)
			Lan_Arr[main_idx + i] = temp[idx1 + i];
}

void Problem1654_Merge(long long start, long long end)
{
	long long mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		Problem1654_Merge(start, mid);
		Problem1654_Merge(mid + 1, end);
		Problem1654_Sort(start, mid + 1, end);
	}
}

int Problem1654()
{
	long long lan_num, target;
	long long  max = 0;
	long long i;


	/* 입력 파트 */
	scanf("%lld %lld", &lan_num, &target);
	for (i = 1; i <= lan_num; i++) {
		scanf("%lld", &Lan_Arr[i]);
		if (Lan_Arr[i] > max)
			max = Lan_Arr[i];
	}

	/* 정렬 파트 */
	Problem1654_Merge(1, lan_num);

	/* 이진 탐색 파트 */
	Problem1654_BS(1, max, target, lan_num);

	/* 결과 출력 */
	printf("%lld\n", result);
}