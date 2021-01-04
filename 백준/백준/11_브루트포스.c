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