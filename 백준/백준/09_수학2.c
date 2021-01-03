#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int math2Problem11() {
	int test_case;
	double x1, y1, r1, x2, y2, r2;
	int i;
	double distance;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
		
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				printf("%d\n", -1);
				continue;
			}
			else {
				printf("%d\n", 0);
				continue;
			}
		}

		distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		
		/*�� ���� �����ϴ� ���*/
		if (distance == r1 + r2)
			printf("%d\n", 1);

		/*�� ���� �Ÿ��� �������� �պ��� �� ���*/
		else if (distance > r1 + r2)
			printf("%d\n", 0);

		/*�� ���� �Ÿ��� �������� �պ��� ����� ���*/
		else {
			/*�� ���� �����ϴ� ���*/
			if (distance == abs(r1 - r2))
				printf("%d\n", 1);

			/*�ϳ��� �� �ȿ� �ٸ� �ϳ��� ���� ���� ���*/
			else if (distance < abs(r1 - r2))
				printf("%d\n", 0);

			/*�� ���� ������ �� ���� ���*/
			else
				printf("%d\n", 2);
		}
	}
}

int math2Problem10() {
	double r;
	double pi = 3.14159265359;

	scanf("%lf", &r);

	printf("%lf\n", r * r * pi);
	printf("%lf\n", r * r * 2);
}


int math2Problem9() {
	int x[3], max;
	int i, pow_length;

	while (1) {
		scanf("%d%d%d", &x[0], &x[1], &x[2]);
		if (x[0] == 0 && x[1] == 0 && x[2] == 0)
			break;

		pow_length = 0;
		max = 0;
		for (i = 1; i <= 2; i++) {
			if (x[max] < x[i])
				max = i;
		}

		for (i = 0; i <= 2; i++) {
			if (i == max)
				continue;
			else
				pow_length = pow_length + x[i] * x[i];
		}

		if ( pow_length == (x[max] * x[max]) )
			printf("right\n");
		else
			printf("wrong\n");
	}
}

/*��� ������ �ƴ� ��� �׹�° �� ���ϴ� ���*/
int math2Problem8ver2() {
	/* ���� ��� : �־��� ���� �� ������ �밢�� �ش��ϴ� ��(���� A�� Ī��)�� ���ؾ���
	 * i) �� ���� ���̸� ������ ������ 0�� ������ ���� ���� or �� ���� �����ؼ� ���̰� ���� �� �� ������ ���� A��
	 * ii) A�� ���ߴٸ�, �ٸ� �� (B, C��� Ī��)���� ���� B + C - A �ϸ� ���� ����*/

	int pos_x[3], pos_y[3];
	int fourth_x, fourth_y;
	int vector1_x, vector1_y, vector2_x, vector2_y, result;
	int A_pos;
	int inner_product;
	int i;

	for (i = 0; i < 3; i++)
		scanf("%d%d", &pos_x[i], &pos_y[i]);

	/* i ���� */
	while (1) {
		vector1_x = pos_x[0] - pos_x[1];
		vector1_y = pos_y[0] - pos_y[1];
		vector2_x = pos_x[0] - pos_x[2];
		vector2_y = pos_y[0] - pos_y[2];
		inner_product = (vector1_x * vector2_x) + (vector1_y * vector2_y);
		if (inner_product == 0) {
			A_pos = 0;
			break;
		}

		vector1_x = pos_x[1] - pos_x[0];
		vector1_y = pos_y[1] - pos_y[0];
		vector2_x = pos_x[1] - pos_x[2];
		vector2_y = pos_y[1] - pos_y[2];
		inner_product = (vector1_x * vector2_x) + (vector1_y * vector2_y);
		if (inner_product == 0) {
			A_pos = 1;
			break;
		}

		vector1_x = pos_x[2] - pos_x[0];
		vector1_y = pos_y[2] - pos_y[0];
		vector2_x = pos_x[2] - pos_x[1];
		vector2_y = pos_y[2] - pos_y[1];
		inner_product = (vector1_x * vector2_x) + (vector1_y * vector2_y);
		if (inner_product == 0) {
			A_pos = 2;
			break;
		}

		printf("���簢���� ���� �� �����ϴ�!\n");
		break;
	}

	/* ii ���� */
	fourth_x = pos_x[0] + pos_x[1] + pos_x[2] - 2 * pos_x[A_pos];
	fourth_y = pos_y[0] + pos_y[1] + pos_y[2] - 2 * pos_y[A_pos];

	printf("%d %d\n", fourth_x, fourth_y);
}

int math2Problem8() {
	int pos_x[3], pos_y[3];
	int fourth_x, fourth_y;
	int i;
	
	for (i = 0; i < 3; i++)
		scanf("%d%d", &pos_x[i], &pos_y[i]);

	fourth_x = (pos_x[0] == pos_x[1]) ? pos_x[2] : (pos_x[0] == pos_x[2]) ? pos_x[1] : pos_x[0];
	fourth_y = (pos_y[0] == pos_y[1]) ? pos_y[2] : (pos_y[0] == pos_y[2]) ? pos_y[1] : pos_y[0];

	printf("%d %d\n",fourth_x, fourth_y);
}

int math2Problem7() {
	int pos_x, pos_y, horizon, vertical;
	int horizon_min, vertical_min, result;
	scanf("%d%d%d%d", &pos_x, &pos_y, &horizon, &vertical);

	/*����(�ʺ�) �ּ� �Ÿ� ���ϱ�*/
	horizon_min = pos_x < (horizon - pos_x) ? pos_x : (horizon - pos_x);
	/*����(����) �ּ� �Ÿ� ���ϱ�*/
	vertical_min = pos_y < (vertical - pos_y) ? pos_y : (vertical - pos_y);
	/*���� �ּ� �Ÿ��� �� ���� �� ���ϱ�*/
	result = horizon_min < vertical_min ? horizon_min : vertical_min;

	printf("%d\n", result);
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

int math2Problem6() {
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

int math2Problem5() {
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

int math2Problem4() {
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

int math2Problem3() {
	int input;
	float sqrt_input;
	int i, flag;

	scanf("%d", &input);
	while (input != 1) {
		sqrt_input = sqrt((double)input);
		flag = 0;

		for (i = 2; i <= sqrt_input; i++) {
			if (input % i == 0) {
				input = input / i;
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			continue;

		printf("%d\n", input);
		input = 1;
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