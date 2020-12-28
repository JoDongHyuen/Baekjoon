#include <stdio.h>

int IFproblem1()
{
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);

	if (a > b)
		printf(">");
	else if (a < b)
		printf("<");
	else if (a == b)
		printf("==");
}

int IFproblem2()
{
	int score;
	
	scanf("%d", &score);

	if (90 <= score)
		printf("A");
	else if (80 <= score)
		printf("B");
	else if (70 <= score)
		printf("C");
	else if (60 <= score)
		printf("D");
	else
		printf("F");
}

int IFproblem3()
{
	int year;

	scanf("%d", &year);

	if (year % 400 == 0)
		printf("1");
	else if (year % 100 != 0 && year % 4 == 0)
		printf("1");
	else
		printf("0");
}

int IFproblem4()
{
	int x, y;


	scanf("%d", &x);
	scanf("%d", &y);

	if (x > 0 && y > 0)
		printf("1");
	else if (x < 0 && y > 0)
		printf("2");
	else if (x < 0 && y < 0)
		printf("3");
	else
		printf("4");


}

int IFproblem5()
{
	int hour, minute;

	scanf("%d", &hour);
	scanf("%d", &minute);

	if (hour == 0)
		if (minute >= 45)
			printf("%d %d", hour, minute - 45);
		else
			printf("23 %d", minute + 15);

	if (hour != 0)
		if (minute >= 45)
			printf("%d %d", hour, minute - 45);
		else
			printf("%d %d", hour - 1,minute + 15);
}

int IFtest()
{
	// ? 연산자 테스트
	int x, y, z, w;
	while (1)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		scanf("%d", &z);
		w = x ? y ? 1 : z ? 2 : 3 : 4;
		printf("결과 : %d\n", w);
		//printf("%d", x ? y ? 11 : 10 : 01);
	}
}