#include <stdio.h>
#include <math.h>

int math2Problem2() {
	int min, max, flag;
	int i, j, sum = 0;
	int result_min = 0;
	int min_check = 0;
	float sqrt_i;
	scanf("%d%d", &min, &max);

	for (i = min; i <= max; i++) {
		flag = 0;

		if (i == 2) {
			result_min = i;
			min_check = 1;
			sum = sum + i;
			continue;
		}

		if ( (i % 2) == 0 || i == 1 )
			continue;

		sqrt_i = sqrt( (double)i );
		for (j = 3; j <= sqrt_i; j++) {
			if ((i % j) == 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			continue;

		if (min_check == 0) {
			min_check = 1;
			result_min = i;
		}
		sum = sum + i;
	}
	if (result_min == 0)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, result_min);
}

int math2Problem1() {
	int test_case;
	int num;
	int i, j, count, flag;
	float sqrt_num;

	count = 0;

	scanf(" %d", &test_case);
	for (i = 0; i < test_case; i++) {
		flag = 0;
		scanf(" %d", &num);

		/*2�� �Ҽ�*/
		if (num == 2)
			count++;

		/*2�� �������� ���� 1�� �Ҽ��� �ƴ�*/
		if ( (num % 2) == 0  || num == 1)
			continue;

		/*�ش� ������ ��Ʈ���� �Ǻ��ϸ� 
		 *����� ��Ʈn���� ����� ���� */
		sqrt_num = sqrt((double)num);
		for (j = 3; j <= sqrt_num; j++)
			if ((num % j) == 0) {
				flag = 1;
				break;
			}
		if (flag == 1)
			continue;

		/*��� ���ǵ��� ���Ÿ� ���, �Ҽ�*/
		count++;
	}
	printf("%d\n", count);
}