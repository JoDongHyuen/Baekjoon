#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _tuple
{
	char str[51];
	int length;
}tuple;

/* �ܾ� ���� ���� */
void Problem8_dict_sort(int start, int end, int length, int pos, tuple input[])
{
	tuple temp;
	char pivot;
	int low = start, high = end, i;
	pivot = input[(start + end) / 2].str[pos];

	while (low <= high)
	{
		while (input[low].str[pos] < pivot) low++;
		while (pivot < input[high].str[pos]) high--;

		if (low <= high)
		{
			temp = input[low];
			input[low] = input[high];
			input[high] = temp;
			low++;
			high--;
		}
	}
	if (start < low - 1)
		Problem8_dict_sort(start, low - 1, length, pos, input);
	if (low < end)
		Problem8_dict_sort(low, end, length, pos, input);
}

void Problem8_dict_Quick(int start, int end, int length, tuple input[])
{
	int pos = 0;
	int local_start = start, local_end = start;

	if (start == end)
		return;

	/* ù��° ���� ���� */
	Problem8_dict_sort(start, end, length, pos, input);
	pos++;
	
	while (1)
	{
		if (pos == length)
			break;
		else
		{
			local_end = local_start;
			while (true)
			{
				if (input[local_end].str[pos - 1] == input[local_end + 1].str[pos - 1])
					local_end++;
				else
				{
					Problem8_dict_sort(local_start, local_end, length, pos, input);
					local_end++;
					local_start = local_end;
				}

				if (local_end == end) {
					Problem8_dict_sort(local_start, local_end, length, pos, input);
					pos++;
					break;
				}
			}
		}
	}
}

/* ���� ���� ���� */
void Problem8_length_sort(int start, int end, tuple input[])
{
	tuple temp;
	int pivot = input[(start + end) / 2].length;
	int low = start, high = end;

	while (low <= high)
	{
		while (input[low].length < pivot) low++;
		while (pivot < input[high].length) high--;
		if (low <= high)
		{
			temp = input[low];
			input[low] = input[high];
			input[high] = temp;
			low++;
			high--;
		}
	}
	if (start < low - 1)
		Problem8_length_sort(start, low - 1, input);
	if (low < end)
		Problem8_length_sort(low, end, input);
}

int sortProblem8()
{
	/* ���� ���� */
	tuple input[20000];
	int test_case;
	int i;
	int start, end, pos;

	/* �Է� ��Ʈ */
	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++) {
		scanf("%s", input[i].str);
		input[i].length = strlen(input[i].str);
	}

	/* �ܾ� ���� ���� ���� ��Ʈ*/
	Problem8_length_sort(0, test_case - 1, input);

	/* ���� ���� �ܾ� ���� ��Ʈ*/
	start = 0;
	end = 0;
	pos = 0;
	while (1)
	{
		if (input[end].length == input[end + 1].length)
			end++;
		else
		{
			Problem8_dict_Quick(start, end, input[end].length, input);
			end++;
			start = end;
		}

		if (end == test_case - 1)
		{
			Problem8_dict_Quick(start, end, input[end].length, input);
			break;
		}
	}

	/* ��� ��Ʈ */
	for (i = 0; i < test_case; i++)
		printf("%s\n", input[i].str);
}

typedef struct _cordinate {
	int x;
	int y;
}cordinate;

int Problem7_x_sort(int start, int mid, int end, cordinate arr[], cordinate temp[])
{
	int idx1 = start, idx2 = mid + 1;
	int main_idx = start;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = arr[i];

	while (idx1 <= mid && idx2 <= end)
	{
		if (temp[idx1].x < temp[idx2].x)
			arr[main_idx++] = temp[idx1++];
		else
			arr[main_idx++] = temp[idx2++];
	}

	if (idx1 <= mid)
		for (i = 0; i <= mid - idx1; i++)  //mid ���� + 1 �Ǿ �Ѿ������ �׳� �Ѿ�����Ŀ� ���� i < mid -idx1�� �ε�ȣ ������ ��������
			arr[main_idx + i] = temp[idx1 + i];
}

int Problem7_x_merge(int start, int end, cordinate arr[], cordinate temp[])
{
	int mid = (start + end) / 2;

	if (start < end) {
		Problem7_x_merge(start, mid, arr, temp);
		Problem7_x_merge(mid + 1, end, arr, temp);
		Problem7_x_sort(start, mid, end, arr, temp);
	}
}

int Problem7_y_sort(int start, int end, cordinate arr[])
{
	cordinate temp;
	int pivot = arr[(start + end) / 2].y;
	int low, high;
	low = start;
	high = end;

	while (low <= high)
	{
		while (arr[low].y < pivot) low++;
		while (pivot < arr[high].y) high--;
		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			low++;
			high--;
		}
	}
	if (start < low - 1)
		Problem7_y_sort(start, low - 1, arr);
	if (low < end)
		Problem7_y_sort(low, end, arr);
}

int sortProblem7()
{
	int start, end;
	int test_case;
	int i;
	cordinate arr[100000], temp[100000];

	/* �Է� ��Ʈ */
	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++)
		scanf("%d%d", &arr[i].x, &arr[i].y);

	/* y�� ���� ��Ʈ */
	Problem7_y_sort(0, test_case - 1, arr);

	/* x�� ���� ��Ʈ */
	start = 0;
	end = 0;
	while(1)
	{
		if (arr[end].y == arr[end + 1].y)
			end++;
		else
		{
			Problem7_x_merge(start, end, arr, temp);
			end++;
			start = end;
		}

		if (end == test_case)
		{
			Problem7_x_merge(start, end - 1, arr, temp);
			break;
		}
	}
	/* ��� ��Ʈ */
	for (i = 0; i < test_case; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
}

void Problem6_y_mergesort(int start, int mid, int end, cordinate cordi[], cordinate temp[])
{
	int arr_idx1, arr_idx2;
	int cordi_idx = start;
	int i;

	arr_idx1 = start;
	arr_idx2 = mid;
	//temp = cordi; �̷� ������ ���� temp�� cordi�� �����Ͱ� ���� cordi ���� ���ϸ� temp ���� ���� ����
	for (i = start; i <= end; i++)
		temp[i] = cordi[i];

	while (arr_idx1 <= mid - 1 && arr_idx2 <= end)
	{
		if (temp[arr_idx1].y < temp[arr_idx2].y)
		{
			cordi[cordi_idx] = temp[arr_idx1];
			arr_idx1++;
			cordi_idx++;
		}
		else
		{
			cordi[cordi_idx] = temp[arr_idx2];
			arr_idx2++;
			cordi_idx++;
		}
	}

	if (arr_idx1 < mid) {
		for (i = 0; i < mid - arr_idx1; i++)
		{
			cordi[cordi_idx + i] = temp[arr_idx1 + i];
		}
	}
}

void Problem6_y_sort(int start, int end, cordinate cordi[], cordinate temp[])
{
	int mid;

	if (start >= end)
		return;
	else
	{
		mid = (start + end) / 2;
		Problem6_y_sort(start, mid, cordi, temp);
		Problem6_y_sort(mid + 1, end, cordi, temp);
		Problem6_y_mergesort(start, mid + 1, end, cordi, temp);
	}
}

void Problem6_x_sort(int start, int end, cordinate cordi[])
{
	int low, high, pivot_value, pivot_pos;
	cordinate temp;

	if (start >= end)
		return;
	else
	{
		low = start;
		high = end;
		pivot_value = cordi[(low + high) / 2].x;
		pivot_pos = (low + high) / 2;

		while (low <= high)
		{
			while (cordi[low].x < pivot_value) low++;
			while (cordi[high].x > pivot_value) high--;
			if (low <= high) {
				temp = cordi[high];
				cordi[high] = cordi[low];
				cordi[low] = temp;
				low++;
				high--;
			}
		}
		//Problem6_x_sort(start, high, cordi);
		//Problem6_x_sort(high + 1, end, cordi); �̷��� �����ÿ� ���� ����� �ȵǾ���
		Problem6_x_sort(start, low - 1, cordi);
		Problem6_x_sort(low, end, cordi);
	}
}

int sortProblem6()
{
	int test_case, input_x, input_y, i;
	int start, end;
	cordinate cordi[100000];
	cordinate temp[100000];

	scanf(" %d", &test_case);
	for (i = 0; i < test_case; i++) 
		scanf(" %d%d", &cordi[i].x, &cordi[i].y);
	
	Problem6_x_sort(0, test_case - 1, cordi);
	start = 0;
	end = 0;
	while(end < test_case)
	{
		if (cordi[end].x == cordi[end + 1].x) {
			end++;
		}
		else {
			Problem6_y_sort(start, end, cordi, temp);
			end++;
			start = end;
		}
	}

	for (i = 0; i < test_case; i++)
		printf("%d %d\n", cordi[i].x, cordi[i].y);
}

int Quick_sort_problem5(int start, int end, int arr[])
{
	int pivot, high, low;
	int i, j, temp;

	pivot = start;
	low = start;
	high = end + 1;
	if (start < end)
	{
		while (true) {
			while (arr[++low] > arr[pivot])
				if (low == end)
					break;
			while (arr[--high] < arr[pivot])
				if (high == start)
					break;

			if (low >= high)
				break;
			temp = arr[high];
			arr[high] = arr[low];
			arr[low] = temp;
		}

		temp = arr[pivot];
		arr[pivot] = arr[high];
		arr[high] = temp;
		pivot = high;


		Quick_sort_problem5(start, pivot - 1, arr);
		Quick_sort_problem5(pivot + 1, end, arr);
	}
}

int sortProblem5()
{
	char input[11] = { 0 };
	int arr[10];
	int i, len;

	scanf("%s", input);

	len = strlen(input);

	for (i = 0; i < len; i++)
		arr[i] = input[i] - 48;

	Quick_sort_problem5(0, len - 1, arr);

	for (i = 0; i < len; i++)
		printf("%d", arr[i]);
}

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

	/*��� ���ķ� ī������ �ϸ�, �ֺ� M�� N�� �󵵸� ���� �� N�� �����ִ� �۾��� ������*/
	for (i = 0; i < number_num; i++) {
		scanf("%d", &input);
		
		/*���� ī�����ϴ� �κ�*/
		if (input < 0) {
			minus_count[-input]++;
			
			/*N�� ���ϴ� �κ�*/
			if (max_freq < minus_count[-input])
				max_freq = minus_count[-input];
		}
		
		/*��� ī���� �ϴ� �κ�*/
		else {
			plus_count[input]++;
			
			/*N�� ���ϴ� �κ�*/
			if (max_freq < plus_count[input])
				max_freq = plus_count[input];
		}

		/*����� ���� ���� ���ϴ� �κ�*/
		sum = sum + input;
	}

	for (i = 4000; i > 0; i--) {
		/*ī������ ������ �迭�� �ִ� �κ�*/
		for (j = 0; j < minus_count[i]; j++)
			sort_result[order++] = -i;

		/*  �ֺ󰪰� Ȥ�� �ֺ��� �������� ��, ���� ���ǿ� �°�
		 * �� ��°�� ���� �ֺ� ���� �����ִ� �κ�*/
		if (freq_count < 2 && max_freq == minus_count[i])
			freq[freq_count++] = -i;
	}

	for (i = 0; i <= 4000; i++) {
		/*ī������ ����� �迭�� �ִ� �κ�*/
		for (j = 0; j < plus_count[i]; j++)
			sort_result[order++] = i;

		/*  �ֺ󰪰� Ȥ�� �ֺ��� �������� ��, ���� ���ǿ� �°�
		* �� ��°�� ���� �ֺ� ���� �����ִ� �κ�*/
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
	/* O(n + k) �����, ũ�Ⱑ ū ���� ���� ��� ��ȿ������ */
	int count[10001] = { 0 };
	int sort_result[10000000] = { 0 };
	int i, j, number_num, number, max = 0;

	scanf("%d", &number_num);

	/*���ڸ� ī�����ϴ� ��Ʈ*/
	for (i = 0; i < number_num; i++) {
		scanf("%d", &number);
		/*��� ���Ŀ� ���� �񱳴� ���� ����*/
		/*���� �ӵ��� ���� �߰��� �κ���*/
		if (max < number)
			max = number;
		count[number]++;
	}

	//for (i = 0; i < max; i++)
	//	count[i + 1] = count[i] + count[i + 1];

	/*  ī���� ����� ����ϴ� �κ�, �ƴϸ� �迭�� ���� ���� ����� �־��൵ ��*/
	for (i = 0; i <= max; i++) {
		if (count[i] != 0)
			for (j = 0; j < count[i]; j++)
				printf("%d\n", i);
	}

}

int Merge(int arr[], int temp[], int start, int mid, int end)
{
	int i;
	int index = start;
	int part1, part2;

	for (i = start; i <= end; i++)
		temp[i] = arr[i];

	part1 = start;
	part2 = mid + 1;

	while (part1 <= mid && part2 <= end) {
		if (temp[part1] < temp[part2])
			arr[index++] = temp[part1++];
		else
			arr[index++] = temp[part2++];
	}

	//�̷��� �ߴٰ� �� �� Ʋ��!!! i�� �ε��� ��ġ�� mid - part1�� ���� ���� �����ε�
	//�������ϸ� �翬�� Ʋ����...!
	//for (i = part1; i <= mid - part1; i++)
	//	arr[index++] = temp[i];

	/*���� �κ��� ���� ����� ���*/
	for (i = 0; i <= mid - part1; i++)
		arr[index + i] = temp[part1 + i];


}

int MergeSort(int arr[], int temp[], int start, int end)
{
	int mid = (start + end) / 2;
	if (start < end) {
		MergeSort(arr, temp, start, mid);
		MergeSort(arr, temp, mid + 1, end);
		Merge(arr, temp, start, mid, end);
	}
}

int sortProblem2verMerge()
{
	int arr[1000000] = { 7,62,0,1,2,2,1,0,62 };
	int temp[1000000];
	int i;

	MergeSort(arr, temp, 0, 8);
	
	for (i = 0; i < 9; i++)
		printf("%d ", arr[i]);
}

void swap_sort(int arr[], int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int Quick_sort(int start, int end, int arr[])
{
	int pivot, low, high, temp, mid, pivot_value;

	if (start >= end)
		return;
	else
	{
		/* 76%���� �ð� �ʰ���*/
		/*
		if (arr[end] < arr[mid]) swap_sort(arr, end, mid);
		if (arr[end] < arr[start]) swap_sort(arr, end, start);
		if (arr[start] < arr[mid]) swap_sort(arr, start, mid);
		*/
		
		
		//pivot = start;

		mid = (start + end) / 2;
		pivot = mid;
		pivot_value = arr[mid];

		//low = start + 1;
		low = start;
		high = end;
		while (1) {
			while (pivot_value > arr[low] && low < end)
				low++;
				

			while (pivot_value < arr[high] && high > start)
				high--;

			if (low >= high)
				break;

			if (low < high) {
				temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
				low++;
				high--;
			}
		}
		/*
		temp = arr[high];
		arr[high] = arr[pivot];
		arr[pivot] = temp;
		*/
	}
	if (high > 1)
		Quick_sort(start, high - 1, arr);
	if (high < end - 1)
		Quick_sort(high + 1, end, arr);
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
	/* ���� ���� */
	/*  n��° ���� �����ؼ� �� �տ� �ִ� ����� ���� n��°�� ���� �� �ڸ��� �������� Ȥ�� ���������� �°� ã�� �� ������
	 * �� ������ ������ ������ - 1 ��ŭ �����ϸ� ��*/
	/* Best�� ��� O(n) = N ������ ���, �־��� ��� O(n) = N^2 �� */

	int number_num, i, j;
	int num[1000], remember, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	/*���������� �����ϴ� �κ�, index �� �����ϴ� �κ� ���� ��� �� ��*/
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
		//��ó�� memcpy�� �б�� ������ ������ ��ġ�� �ȴٸ� ����� ������ �� ����
		//��, ���� �׽�Ʈ�� �ؼ� �ùٸ� ����� ��µǴ��� judge����Ʈ���� Ʋ�� �� �ִٴ� ����
		
		//memmove�� ������� ��, online judge���� ����� �Ǿ���, �׷� �� �������� �����ϱ�?
		//�������� �ٷ� ������ ��� ������, memmove�� ��� ���۸� ����ϱ� ������ �������� �־
		//online judge���� ����� �� ��
		memmove(num + j + 1, num + j, sizeof(int) * (i - j));
		num[j] = remember;
	}


	for (i = 0; i < number_num; i++)
		printf("%d\n", num[i]);
}

int sortProblem1verBubble()
{
	/* ���� ���� */
	/*   i��°�� i + 1��° ���� ���ؼ� �������� Ȥ�� �������� ��쿡 �°� ���ڸ� �ٲٸ鼭, �ڷ��� ������ ���� ������ ( = N )
	 *  �� ������ �ڷ��� ����ŭ ������ ( = N )*/
	/* ��� ��� O(n) = N^2�� */

	int number_num, i, j;
	int num[1000], min, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf("%d", &num[i]);

	/*���������� �����ϴ� �κ�, index �� �����ϴ� �κ� ���� ��� �� ��*/
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
	/* ���� ���� */
	/*  ���� ũ�ų� ���� ���� �ѹ� Ž���� �Ŀ� ( = N )
	 * ù ��° �ڸ��� ���� �ٲ�, �� ������ �ڷ��� �� ��ŭ ������ ( = N )*/
	/* ��� ��� O(n) = N^�� */
	
	int number_num, i, j;
	int num[1000], min, temp;

	scanf("%d", &number_num);

	for (i = 0; i < number_num; i++)
		scanf(" %d", &num[i]);

	/*���������� �����ϴ� �κ�*/
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