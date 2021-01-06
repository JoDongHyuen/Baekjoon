#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prime_num(int num);
int k = 0;
int question2()
{
	int num; scanf("%d", &num);
	int array[100];
	for (int i = 0; i < 100; i++)
		array[i] = -5;
	if (num == 1)
		return 0;
	while (prime_num(num) != 1)
		for (int i = 2; i < sqrt(num); i++)
		{
			if (num % i == 0)
			{
				num = num / i;
				array[k] = i;
				k++;
			}
		}
	for (int i = 0; i < k; i++)
		for (int j = i + 1; j < k; j++)
			if (array[i] > array[j])
			{
				int temp;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
	for (int i = 0; i < k; i++)
		printf("%d\n", array[i]);
	printf("%d ", num);
}
int prime_num(int num)
{
	int k = 2;
	while (1)
	{
		if (k < sqrt(num))
		{
			if (num % k == 0)
				return 0;
			else k++;
		}
		else return 1;
	}
}

int question1()
{
	int num; scanf("%d", &num);
	int* array = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		array[i] = -1;
	if (num == 1)
		return 0;
	while (num != 1)
	{
		for (int i = 2; i < num; i++)
			if (num % i == 0)
			{
				num = num / i;
				array[i] = i;
				break;
			}
	}
	for (int i = 0; i < num; i++)
		if (array[i] != -1)
			printf("%d ", array[i]);
}