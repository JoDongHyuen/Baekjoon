#include <stdio.h>
#include <math.h>
#include <string.h>

int bruteforceProblem2() {
	char str[8];
	int num, decom_sum;
	int i, length, digit, result = 0;

	scanf("%s", str);
	length = (strlen(str) - 1) * 9;
	num = atoi(str);

	//�ð� �ʰ��� �����ϸ� i >= 1 �κ��� ��ó����������
	//�׳� �����ص� �����
	//but ���ڰ� 1,000,000�̶� ���������� 999,000 ��򰡺��ʹ� �������� �ʿ䰡 ������ó��
	//���ڰ� Ŭ�ÿ� i >= 1�� �������ָ� �� ���� performance�� ����
	for (i = num; i >= 1; i--)
	{
		decom_sum = 0;
		decom_sum = decom_sum + i;
		digit = i;
		while (digit) {
			decom_sum = decom_sum + digit % 10;
			digit /= 10;
		}

		if (decom_sum == num)
			result = i;
	}

	printf("%d\n",result);
}

int bruteforceProblem1(){

	int card_num, target_num, i, j, k;
	int result, sum;
	int card[100];

	scanf("%d%d", &card_num, &target_num);

	for (i = 0; i < card_num; i++)
		scanf(" %d", &card[i]);

	// result = card[0] + card[1] + card[2];
	// ���� ���� result�� �ʱ�ȭ�ϸ� result�� target_num���� ū ���� ��� �� ��� 27�� ������ ���ǹ��� ���ǹ�����
	result = 0;

	/*���� ����� �ٻ� ���� ã�ƾ���*/
	for (i = 0; i < card_num - 2; i++)
		for (j = i + 1; j <card_num - 1; j++)
			for (k = j + 1; k < card_num; k++) { //k = i + 2�� �ؼ� �� �� Ʋ���� i = 0, j = 2, k = 2 ��� �ݷʰ� ������
												 //printf("%d %d %d\n", i, j, k);
				sum = card[i] + card[j] + card[k];
				/*������ ����� �� �о �� ��°�� Ʋ��*/
				/*���� ����� ���� �ƴ϶�, ���� ����� �� + ��ǥ ���� ���� �ʾƾ���*/
				if (result < sum && sum <= target_num)
					result = sum;
			}

	printf("%d\n", result);
}