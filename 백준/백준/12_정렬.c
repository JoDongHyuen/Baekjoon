#include <stdio.h>
#include <stdlib.h>

int sortProblem1ver3()
{
	/* ���� ���� */
	/* Best�� ��� O(n) = N ������ ���, �־��� ��� O(n) = N^2 �� */
}

int sortProblem1ver2()
{
	/* ���� ���� */
	/* ��� ��� O(n) = N^2�� */
}

int sortProblem1()
{
	/* ���� ���� */
	/* ��� ��� O(n) = N^�� */
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