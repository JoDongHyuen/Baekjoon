#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortProblem4()
{
	int plus_count[4001] = { 0 };
	int minus_count[4001] = { 0 };
	int sort_result[500000], order = 0;
	int freq[2] = { -4001, -4001 }, freq_count = 0;
	int i, j, number_num, input, sum = 0;
	int mid, range;
	int max_freq = 0;
	//float mean;
	double mean;

	scanf("%d", &number_num);

	/*��� ���ķ� ī������ �ϸ�, �ֺ� M�� N�� �󵵸� ���� �� N�� �����ִ� �۾��� ������*/
	for (i = 0; i < number_num; i++) {
		scanf("%d", &input);
		
		/*���� ī�����ϴ� �κ�*/
		if (input < 0) {
			minus_count[-input]++;
			
			/*N�� ���ϴ� �κ�*/
			if (max_freq < minus_count[-input])
				max_freq = minus_count[-input];
		}
		
		/*��� ī���� �ϴ� �κ�*/
		else {
			plus_count[input]++;
			
			/*N�� ���ϴ� �κ�*/
			if (max_freq < plus_count[input])
				max_freq = plus_count[input];
		}

		/*����� ���� ���� ���ϴ� �κ�*/
		sum = sum + input;
	}

	for (i = 4000; i > 0; i--) {
		/*ī������ ������ �迭�� �ִ� �κ�*/
		for (j = 0; j < minus_count[i]; j++)
			sort_result[order++] = -i;

		/*  �ֺ󰪰� Ȥ�� �ֺ��� �������� ��, ���� ���ǿ� �°�
		 * �� ��°�� ���� �ֺ� ���� �����ִ� �κ�*/
		if (freq_count < 2 && max_freq == minus_count[i])
			freq[freq_count++] = -i;
	}

	for (i = 0; i <= 4000; i++) {
		/*ī������ ����� �迭�� �ִ� �κ�*/
		for (j = 0; j < plus_count[i]; j++)
			sort_result[order++] = i;

		/*  �ֺ󰪰� Ȥ�� �ֺ��� �������� ��, ���� ���ǿ� �°�
		* �� ��°�� ���� �ֺ� ���� �����ִ� �κ�*/
		if (freq_count < 2 && max_freq == plus_count[i])
			freq[freq_count++] = i;
	}

	//mean = (float)sum / order;
	mean = (double)(sum) / (double)order;
	mid = order / 2;
	range = sort_result[order - 1] - sort_result[0];
	printf("%.0lf\n", mean);
	printf("%d\n", sort_result[mid]);
	printf("%d\n", freq_count > 1 ? freq[1] : freq[0]);
 	printf("%d\n", range);
}

int sortProblem3()
{
	/* O(n + k) �����, ũ�Ⱑ ū ���� ���� ��� ��ȿ������ */
	int count[10001] = { 0 };
	int sort_result[10000000] = { 0 };
	int i, j, number_num, number, max = 0;

	scanf("%d", &number_num);

	/*���ڸ� ī�����ϴ� ��Ʈ*/
	for (i = 0; i < number_num; i++) {
		scanf("%d", &number);
		/*��� ���Ŀ� ���� �񱳴� ���� ����*/
		/*���� �ӵ��� ���� �߰��� �κ���*/
		if (max < number)
			max = number;
		count[number]++;
	}

	//for (i = 0; i < max; i++)
	//	count[i + 1] = count[i] + count[i + 1];

	/*  ī���� ����� ����ϴ� �κ�, �ƴϸ� �迭�� ���� ���� ����� �־��൵ ��*/
	for (i = 0; i <= max; i++) {
		if (count[i] != 0)
			for (j = 0; j < count[i]; j++)
				printf("%d\n", i);
	}

}

int Quick_sort(int start, int end, int arr[])
{
	/*1�г� �� �� § ����� �־��µ�, ���� �ٽ� ���� ������ ���� ®��, ���밨 ��*/

	int pivot, low, high, temp;
	//pivot = start;
	pivot = (start + end) / 2;
	if (start >= end)
		return;
	else
	{
		//low = start + 1;
		low = start;
		high = end;

		while (low < high) { //�߾� ���� pivot���� �������� low <= high ���� low < high�� ����
			while (1)
				if (arr[pivot] > arr[low])
					low++;
				else
					break;

			while (1)
				if (arr[pivot] < arr[high])
					high--;
				else
					break;

			if (low < high) {
				temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
			}
		}

		temp = arr[high];
		arr[high] = arr[pivot];
		arr[pivot] = temp;
		pivot = high;
	}
	Quick_sort(0, pivot - 1, arr);
	Quick_sort(pivot + 1, end, arr);
}

int sortProblem2verQuick()
{
	int num[1000000] = { 0 };
	int number_num, i;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	Quick_sort(0, number_num - 1, num);

	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
}

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