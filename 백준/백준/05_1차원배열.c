#include <stdio.h>
#include <stdlib.h>



int ArrPractice7()
{
	float rate;
	int test_case, num, score, avg, i, j, num2;
	int *arr;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++)
	{
		avg = 0;
		num2 = 0;
		scanf("%d", &num);
		arr = malloc(sizeof(int) * num);
		
		for (j = 0; j < num; j++)
		{
			scanf("%d", &score);
			avg += score;
			arr[j] = score;
		}

		avg /= num;

		for (j = 0; j < num; j++)
			if (arr[j] > avg)
				num2++;

		rate = (float)num2 / num * 100;
		printf("%.3f%\n", rate);

		free(arr);
	}
}

int ArrPractice6()
{
	char arr[81];
	int repeat, score, count, i, j;

	scanf("%d", &repeat);

	for (i = 0; i < repeat; i++)
	{
		j = 0;
		score = 0;
		count = 0;
		scanf("%s", arr);
		while (arr[j] != NULL)
		{
			if (arr[j] == 'O')
			{
				j++;
				count++;
			}
			else if (arr[j] == 'X')
			{
				j++;
				score += count * (count + 1) / 2;
				count = 0;
			}
		}
		score += count * (count + 1) / 2;  //마지막이 'O'인경우 while문 안에서 처리를 못해서 추가한 수식

		printf("%d\n", score);
	}
	
}

int ArrPractice5()
{
	int subject, score, i, max = 0;
	float arr[1000], avg = 0;

	scanf("%d", &subject);

	for (i = 0; i < subject; i++)
	{
		scanf("%d", &score);
		arr[i] = score;

		if (score > max)
			max = score;
	}

	for (i = 0; i < subject; i++)
		avg += (arr[i] / max * 100);

	printf("%.3f", avg / subject);
}
int ArrPractice4()
{
	int i, num, output = 0;
	int arr[42] = { 0 };

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		if (arr[num % 42] == 0)
		{
			arr[num % 42]++;
			output++;
		}
	}

	printf("%d", output);
}

int ArrPractice3()
{
	int i, A, B, C, NUM;
	int arr[10] = { 0 };

	scanf("%d%d%d", &A, &B, &C);

	NUM = A * B * C;

	while (NUM)
	{
		arr[NUM % 10]++;
		NUM = NUM / 10;
	}

	for (i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}

int ArrPractice2()
{
	int num, max = 0, i;
	int arr[9] = { 0 };

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
		if (arr[max] < num)
			max = i;
	}
	printf("%d\n%d", arr[max], max + 1);
}

int ArrPractice1()
{
	int num, i, max, min;
	int arr[1000000] = { 0 };

	scanf("%d", &num);

	for (i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	min = arr[0];
	max = arr[0];

	for (i = 0; i < num; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	printf("%d %d", min, max);
}