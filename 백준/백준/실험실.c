#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_pointer_test()
{
	char str1[] = "Hello World";
	char *str2 = "Hi C Language!";

	//str = str + 1; // 얘는 실행 안됨
	str2 = str2 + 1;

	printf("%c", str1[0]);
	//str2[0] = 'X'; // 얘는 컴파일 할 때 에러남

	/* 여기서 알 수 있는 사실, char str1[]은 "포인터 상수"이고 "변수 형태의 문자열"이다!
	 *						   char str2[]은 "포인터 변수"이고 "상수 형태의 문자열"이다! */
}

int strcpy_test()
{
	char str1[] = "Hello World";
	char str2[] = "Hell World";

	//str2 = str1;

	strcpy(str2, str1);

	//printf("%s", str2);  //str2에 \0가 사라져서 안되지렁~
}

int pointer_test2()
{
	int arr[3] = { 11, 22, 33 };
	int *ptr = arr;
	int i;

	for (i = 0; i < 3; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("%x", &ptr[1]);
	ptr[1] = 10;

	//*(ptr + 1) = 20; // ptr + 1한 값을 역참조 하는 것이라 ptr 값 자체가 변하지는 않음
	*(++ptr) = 20; // ptr++는 ptr = ptr + 1 이라서 ptr 값 자체가 변함

	for (i = 0; i < 3; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int pointer_test()
{
	int *num1;
	int *num2;

	num1 = malloc(sizeof(int));
	*num1 = 7;
	num2 = num1;

}

int arrpointer_change(int *arr, int *brr)
{
	int i;
	for (i = 0; i < 5; i++)
		brr[i] = arr[i];
	brr[2] = 5;
}

int arrpointer_insert(int *a, int b[])
{
	b = a;
	//printf("a address: %d\nb address : %d", a, b);
	b[2] = 2;
}

int arrpointer_insert2(int **a)
{
	printf("테스트");
	//arrpointer_insert2(a);
}

int arrpointer_test()
{
	int i;
	int *arr;
	int *brr;
	int arr2[4][5] = { 0 };
	int brr2[5] = { 0 };

	arr = malloc(sizeof(int) * 5);
	brr = malloc(sizeof(int) * 5);
	for (i = 0; i < 5; i++)
		arr[i] = i + 1, brr[i] = 0;
	//printf("%d",sizeof(arr2));
	//arrpointer_insert(arr, brr);
	arrpointer_insert2(arr2);
	//printf("%d, %d", arr2, brr2);
	//brr = arr; // 포인터라서 이런 대입이 가능함
	//brr2 = arr2; // 이건 왜 안되냐? brr2와 arr2는 주소 값이라서 이런 대입이 불가능한 것임
	/* 주소는 변경할 수 없는 값 but 포인터 변수는 주소를 저장하는 '변수'임, 즉 mutable하다는 뜻임 */

	/*함수의 매개변수로 넘겨주는 경우 주소든 포인터든 함수로 넘어갈 땐 포인터로 변함*/
	//arrpointer_insert(arr2, brr2);

	printf("\n");
}

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

	/* memcpy의 경우 현재 내 환경에선 알아서 버퍼를 써서 컴파일되서 그런지 겹치는 부분이 있어도 잘 작동함
	 * but 실행환경이 달라져서 memcpy를 할 때 버퍼를 사용하지 않는 경우도 있음
	 * 이럴 때를 대비해서 겹치는 부분이 있는 경우 무조건 버퍼를 사용하는 memmove 함수를 사용하는 걸 추천함*/
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