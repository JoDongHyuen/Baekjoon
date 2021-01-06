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

	/*맨 위, 오른쪽의 색깔(기준)이 고정되어 있다고 생각해서 한 번 틀림
	 * 기준을 바꿔서 색칠할 경우도 카운트 해주어야함*/
	for (i = 0; i <= row - 8; i++)
		for (j = 0; j <= col - 8; j++) {
			W_std_count = 0;
			B_std_count = 0;
			for (a = i; a < i + 8; a++)
				for (b = j; b < j + 8; b++)
				{
					/*기준이 B인 경우*/
					if ((a + b) % 2 == 0 && chess_board[a][b] == 'W')
						B_std_count++;
					else if ((a + b) % 2 == 1 && chess_board[a][b] == 'B')
						B_std_count++;

					/*기준이 W인 경우*/
					if ((a + b) % 2 == 0 && chess_board[a][b] == 'B')
						W_std_count++;
					else if ((a + b) % 2 == 1 && chess_board[a][b] == 'W')
						W_std_count++;
				}


			// ! 여기서 추가적인 아이디어 W_std_count + B_std_count = 64임, 체스판이 8*8이고 경우의 수가 2가지이기 때문에
			//min_std = (W_std_count < B_std_count) ? W_std_count : B_std_count;
			if (W_std_count < B_std_count)
				min_std = W_std_count;
			else
				min_std = B_std_count;

			if (min_std < min)
				min = min_std;
		}

	printf("%d\n", min);

	/* 체스판 제대로 받아오는지 체크하기 위한 부분
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

	//시간 초과를 걱정하며 i >= 1 부분을 고처보려했지만
	//그냥 제출해도 통과됨
	//but 숫자가 1,000,000이라 가정했을시 999,000 어딘가부터는 연산해줄 필요가 없을때처럼
	//숫자가 클시에 i >= 1을 조정해주면 더 나은 performance가 기대됨
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
	// 위와 같이 result를 초기화하면 result가 target_num보다 큰 값이 들어 갈 경우 27번 라인의 조건문이 무의미해짐
	result = 0;

	/*전수 조사로 근사 값을 찾아야함*/
	for (i = 0; i < card_num - 2; i++)
		for (j = i + 1; j <card_num - 1; j++)
			for (k = j + 1; k < card_num; k++) { //k = i + 2로 해서 한 번 틀렸음 i = 0, j = 2, k = 2 라는 반례가 존재함
												 //printf("%d %d %d\n", i, j, k);
				sum = card[i] + card[j] + card[k];
				/*문제를 제대로 안 읽어서 두 번째로 틀림*/
				/*가장 가까운 값이 아니라, 가장 가까운 값 + 목표 값을 넘지 않아야함*/
				if (result < sum && sum <= target_num)
					result = sum;
			}

	printf("%d\n", result);
}