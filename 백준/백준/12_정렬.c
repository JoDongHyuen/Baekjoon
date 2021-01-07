#include <stdio.h>
#include <stdlib.h>

int sortProblem1ver3()
{
	/* 삽입 정렬 */
	/* Best의 경우 O(n) = N 하지만 평균, 최악의 경우 O(n) = N^2 임 */
}

int sortProblem1ver2()
{
	/* 버블 정렬 */
	/* 모든 경우 O(n) = N^2임 */
}

int sortProblem1()
{
	/* 선택 정렬 */
	/* 모든 경우 O(n) = N^임 */
	int number_num, i, j;
	int num[1000], min, count = 0, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf(" %d", &num[i]);

	for (i = 0; i < number_num; i++) {
		min = i;
		for (j = i; j < number_num; j++) {
			if (num[min] > num[j])
				min = j;
		}

		temp = num[min];
		num[min] = num[i];
		num[i] = temp;
	}

	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
}