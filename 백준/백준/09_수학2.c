#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int math2Problem6() {

}

bool check_prime(int num) {

	int i;
	float sqrt_num;
	
	sqrt_num = sqrt((double)num);

	if (num == 2)
		return true;

	else if (num % 2 == 0 || num == 1)
		return false;

	for (i = 3; i <= sqrt_num; i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}

int math2Problem5() {
	int test_case;
	int input_num, little_prime, big_prime;
	int i, j;
	bool LP_isPrime, BP_isPrime;

	scanf(" %d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf(" %d", &input_num);

		/* ���� ���ǻ� �� �� ���̰� ���� ���� ��Ƽ���� ���ؾ��ϹǷ�
		 *  2�� ���� �Ŀ� �ű⼭ ���� ���ڸ� �۰��ϸ� �Ҽ��� ã�Ƴ���*/
		for (j = input_num / 2; j >= 2; j--) {
			LP_isPrime = check_prime(j);
			if (LP_isPrime == false)
				continue;
			else
				little_prime = j;

			BP_isPrime = check_prime(input_num - j);
			if (BP_isPrime == false)
				continue;
			else
				big_prime = input_num - j;

			printf("%d %d\n", little_prime, big_prime);
			break;
		}
	}
}

int math2Problem4() {
	int input_num, result;
	int i, j, flag;
	float sqrt_i;

	while (1) {
		scanf("%d", &input_num);
		result = 0;

		/*0�� �Է��̸� ���α׷� ����*/
		if (input_num == 0)
			break;

		/* 2n���� �۾ƾ��ϴµ� �ε�ȣ�� <= ���� ����?
		 * =�� ���ԵǸ� 1�� �־��� �� ���������� ��������
		 * �߰������� 2�� ���� ���� �Ҽ��� �� ���� ���⶧���� =�� �־� �������־
		 * ����� �ƹ� ���� ���� */
		for (i = input_num + 1; i <= 2 * input_num; i++) {
			sqrt_i = sqrt((double)i);
			flag = 0;

			/*2�� �Ҽ�ó��*/
			if (i == 2) {
				result++;
				continue;
			}

			/*2�� �������� ���� 1�� �Ҽ��� ó������ ����*/
			else if (i % 2 == 0 || i == 1)
				continue;

			/*i �� 3���� ��Ʈ(i)���� modulus ������ ���� �Ҽ� �Ǻ�*/
			for (j = 3; j <= sqrt_i; j++) {
				if (i % j == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				continue;
			result++;
		}

		/*n�� 2n������ �Ҽ��� ���� ���*/
		printf("%d\n", result);
	}
}

int math2Problem3() {
	int start, end;
	int result;
	int i, j, flag;
	float sqrt_i;

	scanf("%d%d", &start, &end);

	for (i = start; i <= end; i++) {
		flag = 0;
		if (i == 2) {
			printf("%d\n", i);
			continue;
		}

		if ( (i % 2) == 0 || i == 1 )
			continue;

		sqrt_i = sqrt( (double)i );
		for (j = 3; j <= sqrt_i; j++)
			if ((i % j) == 0) {
				flag = 1;
				break;
			}

		if (flag == 1)
			continue;
		printf("%d\n", i);
	}
}

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