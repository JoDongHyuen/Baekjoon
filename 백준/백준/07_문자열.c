#include <stdio.h>
#include <stdlib.h>


int stringProblem10()
{
	char *apb , *arr;
	int test_case, i, j, count = 0;

	scanf("%d", &test_case);

	

	for (i = 0; i < test_case; i++)
	{
		arr = calloc(101, sizeof(char));
		apb = calloc(26, sizeof(char));
		count++;

		scanf("%s", arr);

		for (j = 0; arr[j] != 0; j++)
		{
			if (apb[arr[j] - 'a'] == 1)
			{
				count--;
				break;
			}

			if (apb[arr[j] - 'a'] == 0)
			{
				apb[arr[j] - 'a'] = 1;

				while (arr[j] == arr[j + 1])
					j++;
			}
			
		}

		free(apb);
		free(arr);
	}

	printf("%d", count);
}


int stringProblem9()
{
	char arr[101] = { 0 };
	int i = 0, count = 0;

	scanf("%s", arr);

	while (arr[i] > 0)
	{
		if (arr[i] == 'c' && i < 99)
			if (arr[i + 1] == '=' || arr[i + 1] == '-')
			{
				i = i + 2;
				count++;

				continue;
			}

		if (arr[i] == 'd' && i < 98)
			if (arr[i + 1] == 'z' && arr[i + 2] == '=')
			{
				i = i + 3;
				count++;

				continue;
			}
			else if (arr[i + 1] == '-')
			{
				i = i + 2;
				count++;

				continue;
			}

		if (arr[i] == 'l' && i < 99)
			if (arr[i + 1] == 'j')
			{
				i = i + 2;
				count++;

				continue;
			}

		if (arr[i] == 'n' && i < 99)
			if (arr[i + 1] == 'j')
			{
				i = i + 2;
				count++;

				continue;
			}

		if (arr[i] == 's' && i < 99)
			if (arr[i + 1] == '=')
			{
				i = i + 2;
				count++;

				continue;
			}

		if (arr[i] == 'z' && i < 99)
			if (arr[i + 1] == '=')
			{
				i = i + 2;
				count++;

				continue;
			}

		i++;
		count++;
		
	}

	printf("%d\n", count);
}

int stringProblem8()
{
	char number[16] = { 0 };
	int apb[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	int i = 0, time = 0;

	scanf("%s", number);

	while (number[i] > 0)
	{	
		time += apb[(int)number[i] - 'A'];
		i++;		
	}

	printf("%d", time);
}

int swap1(char *arr)
{
	int temp;

	temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;
}

int stringProblem7()
{
	char num1[4], num2[4];
	int number1, number2;

	scanf("%s%s", num1, num2);

	swap1(num1);
	swap1(num2);

	number1 = atoi(num1);
	number2 = atoi(num2);

	if (number1 > number2)
		printf("%d", number1);
	else
		printf("%d", number2);
}

int stringProblem6()
{
	char str[100] = { 0 };
	int i = 0, count = 1;

	scanf("%[^\n]c", str);

	while (str[i] > 0)
	{
		if (str[i] == ' ')
			count++;

		i++;
	}

	if (str[0] == ' ')
		count--;
	if (str[i - 1] == ' ')
		count--;

	printf("%d\n", count);
}


int stringProblem5()
{
	char str[1000001] = { 0 };
	int apb[26] = { 0 }, i = 0, max, max_pointer;

	scanf("%s", str);

	while (str[i] > 0)
	{
		if (str[i] >= 'a')
			apb[(int)str[i] - 'a'] += 1;
		else
			apb[(int)str[i] - 'A'] += 1;
		i++;
	}

	max = apb[0];
	max_pointer = 0;

	for (i = 0; i < 26; i++)
		if (max < apb[i])
		{
			max = apb[i];
			max_pointer = i;
		}

	for (i = 0; i < 26; i++)
		if (i != max_pointer)
			if (apb[i] == max)
			{
				printf("?");

				return 0;
			}

	printf("%c", max_pointer + 'A');
}


int stringProblem4()
{
	int test_case, i, j, k, repeat;
	char str[21] = { 0 };

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++)
	{
		scanf("%d", &repeat);
		scanf("%s", str);

		j = 0;
		while (str[j] > 0)
		{
			for (k = 0; k < repeat; k++)
				printf("%c", str[j]);
			j++;
		}

		printf("\n");
	}
}

int stringProblem3()
{
	int arr[26], i;
	char String[101] = { 0 };

	scanf("%s", String);

	for (i = 0; i < 26; i++)
		arr[i] = -1;

	for (i = 0; i < 100; i++)
	{
		if (String[i] == 0)
			break;
		
		if (arr[(int)String[i] - 'a'] < 0)
			arr[(int)String[i] - 'a'] = i;
	}

	for (i = 0; i < 26; i++)
		if (i < 25)
			printf("%d ", arr[i]);
		else 
			printf("%d", arr[i]);
}

int stringProblem2()
{
	int num,i, sum;
	char *arr;

	sum = 0;

	scanf("%d", &num);

	arr = malloc(sizeof(char)*num + 1);

	scanf("%s", arr);

	for (i = 0; i < num; i++)
		sum += (int)arr[i] -'0';

	printf("%d\n", sum);
}
int stringProblem1()
{
	char num;

	scanf("%c", &num);

	printf("%d", num);
}