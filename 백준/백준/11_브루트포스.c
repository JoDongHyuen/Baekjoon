#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int bruteforceProblem5() {
	int input;
	int count = 0, i = 655;
	char str[100];
	char *ptr;
	scanf("%d", &input);

	while (true) {
		i++;
		//itoa(i, str, 10);
		sprintf(str, "%d", i);
		ptr = strstr(str, "666");
		if (ptr != NULL)
			count++;
		if (count == input)
			break;
	}
	printf("%d\n", i);
}

int bruteforceProblem4() {
	char chess_board[51][51];
	int i, j, a, b;
	int row, col;
	int min = 2501, min_std;
	int W_std_count, B_std_count;

	scanf("%d%d", &row, &col);

	for (i = 0; i < row; i++)
			scanf("%s", &chess_board[i]);

	/*�� ��, �������� ����(����)�� �����Ǿ� �ִٰ� �����ؼ� �� �� Ʋ��
	 * ������ �ٲ㼭 ��ĥ�� ��쵵 ī��Ʈ ���־����*/
	for (i = 0; i <= row - 8; i++)
		for (j = 0; j <= col - 8; j++) {
			W_std_count = 0;
			B_std_count = 0;
			for (a = i; a < i + 8; a++)
				for (b = j; b < j + 8; b++)
				{
					/*������ B�� ���*/
					if ((a + b) % 2 == 0 && chess_board[a][b] == 'W')
						B_std_count++;
					else if ((a + b) % 2 == 1 && chess_board[a][b] == 'B')
						B_std_count++;

					/*������ W�� ���*/
					if ((a + b) % 2 == 0 && chess_board[a][b] == 'B')
						W_std_count++;
					else if ((a + b) % 2 == 1 && chess_board[a][b] == 'W')
						W_std_count++;
				}


			// ! ���⼭ �߰����� ���̵�� W_std_count + B_std_count = 64��, ü������ 8*8�̰� ����� ���� 2�����̱� ������
			//min_std = (W_std_count < B_std_count) ? W_std_count : B_std_count;
			if (W_std_count < B_std_count)
				min_std = W_std_count;
			else
				min_std = B_std_count;

			if (min_std < min)
				min = min_std;
		}

	printf("%d\n", min);

	/* ü���� ����� �޾ƿ����� üũ�ϱ� ���� �κ�
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