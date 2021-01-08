#include <stdio.h>
#include <stdlib.h>

int sortProblem1verInsertion()
{
	/* 삽입 정렬 */
	/*  */
	/* Best의 경우 O(n) = N 하지만 평균, 최악의 경우 O(n) = N^2 임 */
}

int sortProblem1verBubble()
{
	/* 버블 정렬 */
	/*   i번째랑 i + 1번째 수를 비교해서 오름차순 혹은 내림차순 경우에 맞게 숫자를 바꾸면서, 자료의 마지막 까지 시행함 ( = N )
	 *  위 과정을 자료의 수만큼 시행함 ( = N )*/
	/* 모든 경우 O(n) = N^2임 */

	int number_num, i, j;
	int num[1000], min, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	/*실질적으로 정렬하는 부분, index 값 설정하는 부분 유의 깊게 볼 것*/
	for (i = number_num - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}

	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
}

int sortProblem1verSelection()
{
	/* 선택 정렬 */
	/*  가장 크거나 작은 값을 한번 탐색한 후에 ( = N )
	 * 첫 번째 자리랑 값을 바꿈, 이 과정을 자료의 수 만큼 시행함 ( = N )*/
	/* 모든 경우 O(n) = N^임 */
	
	int number_num, i, j;
	int num[1000], min, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf(" %d", &num[i]);

	/*실질적으로 정렬하는 부분*/
	for (i = 0; i < number_num; i++) {
		min = i;
		for (j = i; j < number_num; j++) {
			if (num[min] > num[j])
				min = j;
		}

		temp = num[min];
		num[min] = num[i];
		num[i] = temp;
	}

	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
}