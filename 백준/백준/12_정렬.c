#include <stdio.h>
#include <stdlib.h>

int sortProblem1verInsertion()
{
	/* ���� ���� */
	/*  */
	/* Best�� ��� O(n) = N ������ ���, �־��� ��� O(n) = N^2 �� */
}

int sortProblem1verBubble()
{
	/* ���� ���� */
	/*   i��°�� i + 1��° ���� ���ؼ� �������� Ȥ�� �������� ��쿡 �°� ���ڸ� �ٲٸ鼭, �ڷ��� ������ ���� ������ ( = N )
	 *  �� ������ �ڷ��� ����ŭ ������ ( = N )*/
	/* ��� ��� O(n) = N^2�� */

	int number_num, i, j;
	int num[1000], min, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	/*���������� �����ϴ� �κ�, index �� �����ϴ� �κ� ���� ��� �� ��*/
	for (i = number_num - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}

	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
}

int sortProblem1verSelection()
{
	/* ���� ���� */
	/*  ���� ũ�ų� ���� ���� �ѹ� Ž���� �Ŀ� ( = N )
	 * ù ��° �ڸ��� ���� �ٲ�, �� ������ �ڷ��� �� ��ŭ ������ ( = N )*/
	/* ��� ��� O(n) = N^�� */
	
	int number_num, i, j;
	int num[1000], min, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf(" %d", &num[i]);

	/*���������� �����ϴ� �κ�*/
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