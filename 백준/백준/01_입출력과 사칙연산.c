#include <stdio.h>

void swap(int *x, int *y) //자료형 다음에 붙는 *(역참조)는 포인터를 의미함
{
	int temp;
	if (*x < *y)  //*(역참조)로 값을 비교 x와 y 
	{
		temp = *y;
		*y = *x;
		*x = temp;            //역참조로 내용물을 바꿈
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

int practice5() //별찍기
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

int practice4() //별찍기
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
	//1. a,b,c 값을 받아내서 정렬을함 O(n^2)
	//2. b는 항상 두번째로 큰 수이다.
	//ps. a b c가 각각 30 30 10 일 경우 두번째로 큰수가 10이라고 생각할 수 있지만 문제에선 30이다.

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	swap(&a, &b); // &(참조)를 통해 변수의 주소값을 swap함수로 호출
	swap(&a, &c);
	swap(&b, &c);

	printf("%d", b);

}



int practice2()
{
	int i, cheap_burger, cheap_drink, cost;
	cheap_burger = 2001;
	cheap_drink = 2001; //문제 조건 중 2000원보다 넘는 가격은 안나오기 때문

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &cost);
		if (i < 3 && cost < cheap_burger) // 1,2,3번째는 햄버거
			cheap_burger = cost;
		else if (i >= 3 && cost < cheap_drink) //4,5번째는 음료수
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