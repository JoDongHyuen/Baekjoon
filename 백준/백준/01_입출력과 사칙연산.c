#include <stdio.h>

void swap(int *x, int *y) //�ڷ��� ������ �ٴ� *(������)�� �����͸� �ǹ���
{
	int temp;
	if (*x < *y)  //*(������)�� ���� �� x�� y 
	{
		temp = *y;
		*y = *x;
		*x = temp;            //�������� ���빰�� �ٲ�
	}
}

int practice6()
{
	int i, j, num;
	scanf("%d", &num);

	for (i = 1; i <= num * 2; i++)
	{
		for (j = 1; j <= num; j++)
			if (i % 2 == 1)
				if (i % 2 == j % 2)
					printf("*");
				else
					printf(" ");
			else
				if (i % 2 == j % 2)
					printf("*");
				else
					printf(" ");

		printf("\n");
	}
}

int practice5() //�����
{
	int i, j, num;
	scanf("%d", &num);

	for (i = 1; i < num * 2; i++)
	{
		if(i <= num)
			for (j = 1; j <= num * 2 - i; j++)
			{
				if (j < i)
					printf(" ");
				else
					printf("*");
			}
		else
			for (j = 1; j <= i; j++)
			{
				if (j < num * 2 - i)
					printf(" ");
				else
					printf("*");
			}
		printf("\n");
	}

}

int practice4() //�����
{
	int i, j, num;
	scanf("%d", &num);

	for (i = 1; i < num * 2; i++)
	{
		if (i < num)
			for (j = 0; j < i; j++)
				printf("*");
		else
			for (j = i; j < num * 2; j++)
				printf("*");
		printf("\n");
	}


}

int practice3()
{
	//1. a,b,c ���� �޾Ƴ��� �������� O(n^2)
	//2. b�� �׻� �ι�°�� ū ���̴�.
	//ps. a b c�� ���� 30 30 10 �� ��� �ι�°�� ū���� 10�̶�� ������ �� ������ �������� 30�̴�.

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	swap(&a, &b); // &(����)�� ���� ������ �ּҰ��� swap�Լ��� ȣ��
	swap(&a, &c);
	swap(&b, &c);

	printf("%d", b);

}



int practice2()
{
	int i, cheap_burger, cheap_drink, cost;
	cheap_burger = 2001;
	cheap_drink = 2001; //���� ���� �� 2000������ �Ѵ� ������ �ȳ����� ����

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &cost);
		if (i < 3 && cost < cheap_burger) // 1,2,3��°�� �ܹ���
			cheap_burger = cost;
		else if (i >= 3 && cost < cheap_drink) //4,5��°�� �����
			cheap_drink = cost;
	}

	printf("%d", cheap_burger + cheap_drink - 50);
}

int practice1()
{
	int i, score, arg;

	arg = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &score);
		if (score < 40)
			score = 40;
		arg = arg + score;
	}

	printf("%d", arg / 5);
}

int stardot1(int num, int count)
{
	int i, j;
	j = count;

	/*center star*/
	if (num - count < 2)
	{
		for (i = 0; i < num; i++)
			printf(" ");
		printf("*");
		printf("\n");
		return 0;
	}

	/* upward star*/
	for (i = 0; i < num * 2 - j; i++)
	{
		if (i > j)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");

	/*recursive dot*/
	stardot1(num, ++count);

	/*downward star*/
	for (i = 0; i < num * 2 - j; i++)
	{
		if (i > j)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");


}

int star1()
{
	int num, count = 0;

	scanf("%d", &num);

	stardot1(num, count);

}