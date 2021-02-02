#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int for_condition_text()
{
	int i, j = 10;

	/*이렇게 조건문을 넣으면 몇번 프린트 될지 실험*/
	for (i = 0; i < j - i; i++)
		printf("%d 번째 프린트\n", i);
	/*실험 결과 : 10번 프린트 되지 않음*/
}

int plus_test(int a, int b)
{
	return a + b;
}

int plus_test_main()
{
	int a = 10, b = 20, c;
	//c = plus_test(a++, b); // 결과는 30이다
	c = plus_test(a + 1, b);
	printf("%d\n", c);
}

int scanf_test() {
	int arr[10];

	scanf("%d", arr[2]);
	scanf("%d", arr[1]);
}

int arr_minus_test() {

	/*변수에 minus 붙여도 제대로 작동함*/
	int a = -1;
	int arr[2] = { 12, 34 };

	printf("%d\n", arr[-a]);
}

int typecasting_test() {

	int a = 10, b = 3;
	float c;

	/*정수끼리 나눠서 타입캐스팅 해봤자 소수점은 반영안됨*/
	//c = (float)(a / b);

	/*float를 정수로 나누면 소수점은 반영됨*/
	c = (float)a / b;

	printf("%f\n", c);
}

int memcpy_test() {
	int a[] = { 1, 2, 3, 4, 5 };
	int i;

	memcpy(a, a + 1, sizeof(int) * 4);

	for (i = 0; i < 5; i++)
		printf("%d ", a[i]); //2 2 3 4 5 가 출력됨
}

int plus_speed_test() {
	int i = 0;

	while (1)
		printf("%d\n", i++);
}
int test_atoi() {
	char *str = "213";
	int num;
	int arr[3];

	num = atoi(str);
	
	/* str[0]는 pointer형식이 아니라 atoi하면 에러가 발생함*/
	arr[0] = atoi(str[0]); 

	printf("%d\n", num);
}

int basic1()
{
	char a;
	int b1;
	long int b2;
	long long int b3;
	float c1;
	long float c2;
	double d1;
	long double d2;
	long e1;
	long long e2;

	printf("char : %d\n", sizeof(a));
	printf("int : %d\n", sizeof(int));
	printf("long int : %d\n", sizeof(b2));	
	printf("long long int : %d\n", sizeof(b3));
	printf("float : %d\n", sizeof(c1));
	printf("long float : %d\n", sizeof(c2));
	printf("double : %d\n", sizeof(d1));
	printf("long double : %d\n", sizeof(d2));
	printf("long : %d\n", sizeof(e1));
	printf("long long : %d\n", sizeof(e2));



}

int basic2()
{
	int i, j;

	scanf("%d%d", &i, &j);

	while (i != 0 || j != 0)
	{
		printf("실행됨\n");
		scanf("%d%d", &i, &j);

	}
}

int basic3()
{
	int a;
	int *i;
	char *j;


	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(j));



	a = 10;

	printf("%d\n", a); 
	printf("%d\n", sizeof(a));

	(float)a = 3.14;

	printf("%f\n", a);
	printf("%d\n", sizeof(a));
}