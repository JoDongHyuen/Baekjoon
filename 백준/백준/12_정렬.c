#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortProblem4()
{
	int plus_count[4001] = { 0 };
	int minus_count[4001] = { 0 };
	int sort_result[500000], order = 0;
	int freq[2] = { -4001, -4001 }, freq_count = 0;
	int i, j, number_num, input, sum = 0;
	int mid, range;
	int max_freq = 0;
	//float mean;
	double mean;

	scanf("%d", &number_num);

	/*계수 정렬로 카운팅을 하며, 최빈값 M이 N의 빈도를 가질 때 N을 구해주는 작업을 병행함*/
	for (i = 0; i < number_num; i++) {
		scanf("%d", &input);
		
		/*음수 카운팅하는 부분*/
		if (input < 0) {
			minus_count[-input]++;
			
			/*N을 구하는 부분*/
			if (max_freq < minus_count[-input])
				max_freq = minus_count[-input];
		}
		
		/*양수 카운팅 하는 부분*/
		else {
			plus_count[input]++;
			
			/*N을 구하는 부분*/
			if (max_freq < plus_count[input])
				max_freq = plus_count[input];
		}

		/*평균을 내기 위해 합하는 부분*/
		sum = sum + input;
	}

	for (i = 4000; i > 0; i--) {
		/*카운팅한 음수를 배열에 넣는 부분*/
		for (j = 0; j < minus_count[i]; j++)
			sort_result[order++] = -i;

		/*  최빈값과 혹은 최빈값이 여러개일 때, 문제 조건에 맞게
		 * 두 번째로 작은 최빈 값을 구해주는 부분*/
		if (freq_count < 2 && max_freq == minus_count[i])
			freq[freq_count++] = -i;
	}

	for (i = 0; i <= 4000; i++) {
		/*카운팅한 양수를 배열에 넣는 부분*/
		for (j = 0; j < plus_count[i]; j++)
			sort_result[order++] = i;

		/*  최빈값과 혹은 최빈값이 여러개일 때, 문제 조건에 맞게
		* 두 번째로 작은 최빈 값을 구해주는 부분*/
		if (freq_count < 2 && max_freq == plus_count[i])
			freq[freq_count++] = i;
	}

	//mean = (float)sum / order;
	mean = (double)(sum) / (double)order;
	mid = order / 2;
	range = sort_result[order - 1] - sort_result[0];
	printf("%.0lf\n", mean);
	printf("%d\n", sort_result[mid]);
	printf("%d\n", freq_count > 1 ? freq[1] : freq[0]);
 	printf("%d\n", range);
}

int sortProblem3()
{
	/* O(n + k) 라고함, 크기가 큰 값이 있을 경우 비효율적임 */
	int count[10001] = { 0 };
	int sort_result[10000000] = { 0 };
	int i, j, number_num, number, max = 0;

	scanf("%d", &number_num);

	/*숫자를 카운팅하는 파트*/
	for (i = 0; i < number_num; i++) {
		scanf("%d", &number);
		/*계수 정렬에 원래 비교는 쓰지 않음*/
		/*단지 속도를 위해 추가한 부분임*/
		if (max < number)
			max = number;
		count[number]++;
	}

	//for (i = 0; i < max; i++)
	//	count[i + 1] = count[i] + count[i + 1];

	/*  카운팅 결과를 출력하는 부분, 아니면 배열을 따로 만들어서 결과를 넣어줘도 됨*/
	for (i = 0; i <= max; i++) {
		if (count[i] != 0)
			for (j = 0; j < count[i]; j++)
				printf("%d\n", i);
	}

}

int Quick_sort(int start, int end, int arr[])
{
	/*1학년 때 못 짠 기억이 있었는데, 지금 다시 보니 굉장히 쉽게 짰음, 성취감 굿*/

	int pivot, low, high, temp;
	//pivot = start;
	pivot = (start + end) / 2;
	if (start >= end)
		return;
	else
	{
		//low = start + 1;
		low = start;
		high = end;

		while (low < high) { //중앙 값을 pivot으로 쓰기위해 low <= high 에서 low < high로 변경
			while (1)
				if (arr[pivot] > arr[low])
					low++;
				else
					break;

			while (1)
				if (arr[pivot] < arr[high])
					high--;
				else
					break;

			if (low < high) {
				temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
			}
		}

		temp = arr[high];
		arr[high] = arr[pivot];
		arr[pivot] = temp;
		pivot = high;
	}
	Quick_sort(0, pivot - 1, arr);
	Quick_sort(pivot + 1, end, arr);
}

int sortProblem2verQuick()
{
	int num[1000000] = { 0 };
	int number_num, i;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	Quick_sort(0, number_num - 1, num);

	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
}

int sortProblem1verInsertion()
{
	/* 삽입 정렬 */
	/*  n번째 값을 선택해서 그 앞에 있는 값들과 비교해 n번째의 값이 들어갈 자리를 오름차순 혹은 내림차순에 맞게 찾은 후 삽입함
	 * 위 과정을 졍렬할 숫자의 - 1 만큼 시행하면 됨*/
	/* Best의 경우 O(n) = N 하지만 평균, 최악의 경우 O(n) = N^2 임 */

	int number_num, i, j;
	int num[1000], remember, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	/*실질적으로 정렬하는 부분, index 값 설정하는 부분 유의 깊게 볼 것*/
	for (i = 1; i < number_num; i++) {
		remember = num[(j = i)];
		while (j > 0) {
			if (num[j - 1] < remember) break;
			else {
				//num[j] = num[j - 1];
				j--;
			}
		}
		if (j == i) continue;
		//memcpy(num + j + 1, num + j, sizeof(int) * (i - j));
		//위처럼 memcpy의 읽기와 쓰기의 영역이 겹치게 된다면 결과를 정의할 수 없음
		//즉, 내가 테스트를 해서 올바른 결과가 출력되더라도 judge사이트에선 틀릴 수 있다는 말임
		
		//memmove를 사용했을 땐, online judge에서 통과가 되었음, 그럼 그 차이점이 무엇일까?
		//차이점은 바로 버퍼의 사용 유무임, memmove의 경우 버퍼를 사용하기 때문에 안정성이 있어서
		//online judge에서 통과된 듯 함
		memmove(num + j + 1, num + j, sizeof(int) * (i - j));
		num[j] = remember;
	}


	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
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