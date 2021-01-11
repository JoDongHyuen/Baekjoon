#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortProblem1verInsertion()
{
	/* ���� ���� */
	/*  n��° ���� �����ؼ� �� �տ� �ִ� ����� ���� n��°�� ���� �� �ڸ��� �������� Ȥ�� ���������� �°� ã�� �� ������
	 * �� ������ ������ ������ - 1 ��ŭ �����ϸ� ��*/
	/* Best�� ��� O(n) = N ������ ���, �־��� ��� O(n) = N^2 �� */

	int number_num, i, j;
	int num[1000], remember, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	/*���������� �����ϴ� �κ�, index �� �����ϴ� �κ� ���� ��� �� ��*/
	for (i = 1; i < number_num; i++) {
		remember = num[(j = i)];
		while (j > 0) {
			if (num[j - 1] < remember) break;
			else {
				//num[j] = num[j - 1];
				j--;
			}
		}
		if (j == i) continue;
		//memcpy(num + j + 1, num + j, sizeof(int) * (i - j));
		//��ó�� memcpy�� �б�� ������ ������ ��ġ�� �ȴٸ� ����� ������ �� ����
		//��, ���� �׽�Ʈ�� �ؼ� �ùٸ� ����� ��µǴ��� judge����Ʈ���� Ʋ�� �� �ִٴ� ����
		
		//memmove�� ������� ��, online judge���� ����� �Ǿ���, �׷� �� �������� �����ϱ�?
		//�������� �ٷ� ������ ��� ������, memmove�� ��� ���۸� ����ϱ� ������ �������� �־
		//online judge���� ����� �� ��
		memmove(num + j + 1, num + j, sizeof(int) * (i - j));
		num[j] = remember;
	}


	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
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