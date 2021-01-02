#include <stdio.h>
#include <string.h>
#include <math.h>

int math1Problem9()
{
	int test_case, result;
	int x, y, dist;
	int sqrt_int;
	float sqrt_float;
	int i, j, k;

	scanf(" %d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf("%d%d", &x, &y);
		dist = y - x;

		sqrt_float = sqrt((double)dist);
		sqrt_int = (int)sqrt_float;

		/*���� ���� ���*/
		if ((sqrt_float - (float)sqrt_int) == 0) {
			result = sqrt_int * 2 - 1;
			printf("%d\n", result);
		}

		/*���� ���� �ƴ� ���*/
		else {
			/*�������� �ƴ� ��� sqrt_int(=sqrt�� bottom) * 2 - 1 ����
			 *������ 1 Ȥ�� 2�� ũ�⶧���� �ϴ� 1�� �����ְ� ����*/
			result = sqrt_int * 2;

			/*sqrt_int�� ���� < dist <sqrt_int+1�� ���� ������ ��
			 *���̿� �ִ� ������ �ݺ��� ũ�� 1�� �����ָ� ��*/
			if (((sqrt_int * sqrt_int) + sqrt_int) < dist)
				result++;
			printf("%d\n", result);
		}
	}
}

int math1Problem8() {
	char input[10001];
	int i, length, max_len, flag = 0;
	int num1[10001] = { 0 }, num2[10001] = { 0 };

	/*input�� string���� �޾� num1�� �������� char���� int�� ��ȯ�� �־���*/
	scanf("%s", input);
	length = strlen(input);
	max_len = length;

	for (i = 0; i < length; i++)
		num1[i] = input[length - (i + 1)] - 48;

	/*�ٽ� �ѹ� input�� string���� �޾� num2�� char���� int�� ��ȯ�� �������� �־���*/
	scanf("%s", input);
	length = strlen(input);
	if (max_len < length)
		max_len = length;

	for (i = 0; i < length; i++)
		num2[i] = input[length - (i + 1)] - 48;

	/*���������� �����ϴ� ��Ʈ*/
	for (i = 0; i < max_len; i++) {
		num1[i] = num1[i] + num2[i];
		if (num1[i] >= 10) {

			/*���� ���� �ڸ� �� �ø� üũ*/
			/*why? ����� ���� ���ؼ�*/
			if (i == (max_len - 1))
				flag = 1;

			num1[i] = num1[i] % 10;
			num1[i + 1]++;
		}
	}

	/*����ϴ� ��Ʈ*/
	for (i = max_len - 1 + flag; i >= 0; i--)
		printf("%d", num1[i]);
	printf("\n");

}

int combination(int a, int b)
{
	if (a == b || b == 0)
		return 1;
	else
		return ( combination(a - 1, b - 1) + combination(a - 1, b) );
}

int math1Problem7()
{
	int test_case;
	int k, n, i, j, loop, std;
	int result;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++)
	{
		result = 1;

		scanf("%d%d", &k, &n);

		std = k + n;
		loop = k + 1;

		result = combination(std, loop);
		//for (j = 0; j < loop; j++)
			//result = result * std--; //�̷��� Ǯ�� overflow��

		//for (j = 1; j <= loop; j++)
			//result = result / j;

		printf("%d\n", result);
	}
}

int math1Problem6()
{
	int H, W, N, test_case; //H�� ȣ�� ����, W�� ȣ���� ȣ��, N�� N��° �մ�
	int i;
	int custom_H, custom_W;

	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++)
	{
		scanf("%d%d%d", &H, &W, &N);

		if (N % H != 0)
		{
			custom_H = N % H;
			custom_W = N / H + 1;
		}
		else
		{
			custom_H = H;
			custom_W = N / H;
		}
		printf("%d%02d\n", custom_H, custom_W);
	}
}

int math1PRoblem5()
{
	int A, B, C, count = 1;

	scanf("%d%d%d", &A, &B, &C);

	if ((C - B) % (A - B) == 0)
		count = (C - B) / (A - B);
	else
		count = (C - B) / (A - B) + 1;

	printf("%d", count);
}

int math1Problem4()
{
	int num, x = 1;

	scanf("%d", &num);

	while (num > (x * (x + 1) / 2))
		x++;

	num = num - (x - 1)*x / 2;

	if ((x % 2) == 0)
		printf("%d/%d", num, x - num + 1);
	else
		printf("%d/%d", x - num + 1, num);

}

int math1Problem3()
{
	int N, count, min, max;
	min = 2, max = 7, count = 1;

	scanf("%d", &N);

	if (N == 1)
		printf("%d", count);
	else
	{
		while (1)
		{
			if (min <= N && N <= max)
				break;
			min = min + 6 * count;
			count++;
			max = max + 6 * count;
		}

	count++;
	printf("%d", count);
	}

}

int math1Problem2()
{
	int N, count3 = 0, count5 = 0;

	scanf("%d", &N);

	while (N >= 3)
	{
		if ((N % 5) == 0)
		{
			count5 = N / 5;
			N = 0;
			break;
		}

		N -= 3;
		count3++;
	}
	
	if (N == 1 || N == 2)
		printf("%d", -1);
	else
		printf("%d", count3 + count5);
}

int math1Problem1()
{
	int A, B, C;

	scanf("%d%d%d", &A, &B, &C);

	if (B >= C)
		printf("%d", -1);
	else
		printf("%d", A / (C - B) + 1);
}