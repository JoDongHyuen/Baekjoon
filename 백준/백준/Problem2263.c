#include <stdio.h>
#include <stdlib.h>

int In_Order[100001];
int Post_Order[100001];
int Idx[100001];

void Pre_Order(int inbegin, int inend, int postbegin, int postend)
{
	if (inbegin <= inend && postbegin <= postend)
	{
		int rootidx, leftsize, rightsize;

		printf("%d ", Post_Order[postend]);

		rootidx = Idx[Post_Order[postend]];
		leftsize = rootidx - inbegin;
		rightsize = inend - rootidx;

		Pre_Order(inbegin, rootidx - 1, postbegin, postbegin + leftsize - 1);
		Pre_Order(rootidx + 1, inend, postend - rightsize, postend - 1);
	}
}

int Problem2263()
{
	int n, i;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &In_Order[i]);

	for (i = 1; i <= n; i++)
		scanf("%d", &Post_Order[i]);

	// 이거 Idx 쓰는 아이디어 생각치도 못했다!
	for (i = 1; i <= n; i++)
		Idx[In_Order[i]] = i;

	Pre_Order(1, n, 1, n);

}