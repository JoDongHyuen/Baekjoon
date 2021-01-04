#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


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