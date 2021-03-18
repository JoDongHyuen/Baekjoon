#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char channel[7] = { 0 };
char find[7] = { 0 };
char str[7];
int Button[10] = { 0 };
int near = -1;

void Problem1107_Backtracking(int depth, int pos)
{
	int i;
	if (pos >= 1) {
		if (near == -1) {
			near = atoi(find);
			sprintf(str, "%d", near);
		}
		if (abs(atoi(channel) - atoi(find)) < abs(atoi(channel) - near)) {
			near = atoi(find);
			sprintf(str, "%d", near);
		}
	}

	if (pos < depth)
	{
		for (i = 0; i < 10; i++)
			if (Button[i] == 0) {
				find[pos] = i + '0';
				Problem1107_Backtracking(depth, pos + 1);
			}
	}

}

int Problem1107()
{
	int Error_Num, check;
	int i, gap;
	int *ptr;

	scanf("%s", &channel);
	scanf("%d", &Error_Num);

	for (i = 0; i < Error_Num; i++) {
		scanf("%d", &check);
		Button[check] = 1;
	}

	gap = abs(atoi(channel) - 100); // 오로지 + - 버튼으로만 움직였을 경우

	if (Error_Num == 10) // 10개 버튼이 다 고장난 경우
		printf("%d\n", gap);

	else if (Error_Num == 0) // 고장난 버튼이 한개도 없을 경우
		printf("%d\n", strlen(channel) < gap ? strlen(channel) : gap);

	else {
		for (i = 1; i <= strlen(channel) + 1; i++)
			if (i < 7)
				Problem1107_Backtracking(i, 0);
		printf("%d\n",  (strlen(str) + abs(atoi(channel) - near)) < gap ? (strlen(str) + abs(atoi(channel) - near)) : gap);
	}


}