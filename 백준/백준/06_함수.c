#include <stdio.h>
#include <stdlib.h>

void HansuCount(int value, int num, int* count)
{
	int check_value;

	check_value = num % 10 - num / 10 % 10;

	if (check_value == value)
	{
		if (num < 100)
			*count++;
		else
			HansuCount(check_value, num / 10, count);
	}
}

int HansuProblem()
{
	int *count;
	int num, i, value;

	scanf("%d", &num);

	count = malloc(sizeof(int));
	
	*count = 99;

	if (num >= 100)
	{
		for (i = num; i >= 100; i--)
		{
			value = i % 10 - i / 10 % 10;
			HansuCount(value, i / 10, count);
		}
		printf("%d\n", *count);
	}
	else
		printf("%d\n", num);

	free(count);
}

int SelfNumber(int a, int* arr)
{
	if (a >= 10000 )
		return 0;

	int sum, factor;

	sum = a;

	do {
		sum += a % 10;
		a /= 10;
	} while (a != 0);
	
	if (sum <= 10000) 
	{
		if (arr[sum] == 1)		//연산 시간 축소를 위해서 같은 숫자가 나오면 재귀를 멈춤
			return 0;

		arr[sum] = 1;			//selfnumber가 아닌 숫자를 arr배열에 표시함
	}
	SelfNumber(sum, arr);
}

int SelfNumberProblem()
{
	int num = 1, i;
	int arr[10001] = { 0 };
	
	do {
		if (arr[num] == 0)
			SelfNumber(num, arr);
		num++;
	} while (num < 10000);

	for (i = 1; i <= 10000; i++)      //num
		if (arr[i] == 0)
			printf("%d\n", i);

}

long long SumNumber(int *arr, int n)
{
	int i, sum = 0;

	for (i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

int functionTest()
{
	long long sum;
	int n, i;
	int *arr;

	scanf("%d",&n);

	arr = malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sum = SumNumber(arr, n);

	printf("%lld", sum);

	free(arr);
}
