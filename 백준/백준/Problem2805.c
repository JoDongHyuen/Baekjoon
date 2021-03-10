#include <stdio.h>

long long result = 0;
long long tree[1000000];
long long temp[1000000];

void Problem2805_Sort(int start, int mid, int end)
{
	int main_idx = start, idx1 = start, idx2 = mid;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = tree[i];

	while (idx1 <= (mid - 1) && idx2 <= end)
	{
		if (temp[idx1] <= temp[idx2])
			tree[main_idx++] = temp[idx1++];
		else
			tree[main_idx++] = temp[idx2++];
	}

	if (idx1 < mid)
		for (i = 0; i < mid - idx1; i++)
			tree[main_idx + i] = temp[idx1 + i];
}

void Problem2805_Merge(int start, int end)
{
	int mid = (start + end) / 2;

	if (start < end)
	{
		Problem2805_Merge(start, mid);
		Problem2805_Merge(mid + 1, start);
		Problem2805_Sort(start, mid + 1, end);
	}
}

void Problem2805_BS(int start, int end, int target, int tree_num)
{
	int mid = (start + end) / 2;
	int i;
	long long sum = 0, cut;

	if (start > end)
		return;
	else
	{
		for (i = 0; i < tree_num; i++) {
			cut = tree[i] - mid;
			if (cut > 0)
				sum += cut;
		}

		if (sum >= target) {
			if (mid > result)
				result = mid;
			Problem2805_BS(mid + 1, end, target, tree_num);
		}
		else
			Problem2805_BS(start, mid - 1, target, tree_num);
	}
}

int Problem2805()
{
	int tree_num;
	long long target;
	int i, max = 0;

	scanf("%d %lld", &tree_num, &target);
	for (i = 0; i < tree_num; i++) {
		scanf("%lld", &tree[i]);
		if (tree[i] > max)
			max = tree[i];
	}

	/* 정렬 파트 */
	Problem2805_Merge(0, tree_num - 1);

	/* 이진 탐색 파트 */
	Problem2805_BS(0, max, target, tree_num);

	printf("%lld\n", result);
}