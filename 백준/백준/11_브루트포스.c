#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int bruteforceProblem4() {
	char chess_board[49][49];
	int i, j, k, l;
	int row, col;
	int min = 2501;
	int W_std_count, B_std_count;

	scanf("%d%d", &row, &col);

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			scanf(" %c", &chess_board[i][j]);

	/*�� ��, �������� ����(����)�� �����Ǿ� �ִٰ� �����ؼ� �� �� Ʋ��
	 * ������ �ٲ�ĥ�� ��쵵 ī��Ʈ ���־����*/
	for (i = 0; i <= row - 8; i++)
		for (j = 0; j <= col - 8; j++) {
			W_std_count = 0;
			B_std_count = 0;
			if (chess_board[i][j] == 'B') {
				for (k = i; k < i + 8; k = k++)
					for (l = j; l < j + 8; l++)
						if ((k + l) % 2 == 0 && chess_board[k][l] == 'W')
							count++;
						else if ((k + l) % 2 == 1 && chess_board[k][l] == 'B')
							count++;
			}
			else if (chess_board[i][j] == 'W') {
				for (k = i; k < i + 8; k++)
					for (l = j; l < j + 8; l++)
						if ((k + l) % 2 == 0 && chess_board[k][l] == 'B')
							count++;
						else if ((k + l) % 2 == 1 && chess_board[k][l] == 'W')
							count++;
			}

			if (count < min)
				min = count;
		}

	printf("%d\n", min);
	/*
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			printf("%c", chess_board[i][j]);
		printf("\n");
	}*/
}

int bruteforceProblem3() {
	int person_num, kg[50] = { 0 }, cm[50] = { 0 };
	int i, j , count;

	scanf("%d", &person_num);

	for (i = 0; i < person_num; i++)
		scanf(" %d%d", &kg[i], &cm[i]);

	for (i = 0; i < person_num; i++) {
		count = 0;
		for (j = 0; j < person_num; j++)
			if (i != j && kg[i] < kg[j] && cm[i] < cm[j]) {
				count++;
			}
		printf("%d ", count + 1);
	}
}

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