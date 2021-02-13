#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_pointer_test()
{
	char str1[] = "Hello World";
	char *str2 = "Hi C Language!";

	//str = str + 1; // ��� ���� �ȵ�
	str2 = str2 + 1;

	printf("%c", str1[0]);
	//str2[0] = 'X'; // ��� ������ �� �� ������

	/* ���⼭ �� �� �ִ� ���, char str1[]�� "������ ���"�̰� "���� ������ ���ڿ�"�̴�!
	 *						   char str2[]�� "������ ����"�̰� "��� ������ ���ڿ�"�̴�! */
}

int strcpy_test()
{
	char str1[] = "Hello World";
	char str2[] = "Hell World";

	//str2 = str1;

	strcpy(str2, str1);

	//printf("%s", str2);  //str2�� \0�� ������� �ȵ�����~
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

	//*(ptr + 1) = 20; // ptr + 1�� ���� ������ �ϴ� ���̶� ptr �� ��ü�� �������� ����
	*(++ptr) = 20; // ptr++�� ptr = ptr + 1 �̶� ptr �� ��ü�� ����

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
	printf("�׽�Ʈ");
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
	//brr = arr; // �����Ͷ� �̷� ������ ������
	//brr2 = arr2; // �̰� �� �ȵǳ�? brr2�� arr2�� �ּ� ���̶� �̷� ������ �Ұ����� ����
	/* �ּҴ� ������ �� ���� �� but ������ ������ �ּҸ� �����ϴ� '����'��, �� mutable�ϴٴ� ���� */

	/*�Լ��� �Ű������� �Ѱ��ִ� ��� �ּҵ� �����͵� �Լ��� �Ѿ �� �����ͷ� ����*/
	//arrpointer_insert(arr2, brr2);

	printf("\n");
}

int for_condition_text()
{
	int i, j = 10;

	/*�̷��� ���ǹ��� ������ ��� ����Ʈ ���� ����*/
	for (i = 0; i < j - i; i++)
		printf("%d ��° ����Ʈ\n", i);
	/*���� ��� : 10�� ����Ʈ ���� ����*/
}

int plus_test(int a, int b)
{
	return a + b;
}

int plus_test_main()
{
	int a = 10, b = 20, c;
	//c = plus_test(a++, b); // ����� 30�̴�
	c = plus_test(a + 1, b);
	printf("%d\n", c);
}

int scanf_test() {
	int arr[10];

	scanf("%d", arr[2]);
	scanf("%d", arr[1]);
}

int arr_minus_test() {

	/*������ minus �ٿ��� ����� �۵���*/
	int a = -1;
	int arr[2] = { 12, 34 };

	printf("%d\n", arr[-a]);
}

int typecasting_test() {

	int a = 10, b = 3;
	float c;

	/*�������� ������ Ÿ��ĳ���� �غ��� �Ҽ����� �ݿ��ȵ�*/
	//c = (float)(a / b);

	/*float�� ������ ������ �Ҽ����� �ݿ���*/
	c = (float)a / b;

	printf("%f\n", c);
}

int memcpy_test() {
	int a[] = { 1, 2, 3, 4, 5 };
	int i;

	memcpy(a, a + 1, sizeof(int) * 4);

	for (i = 0; i < 5; i++)
		printf("%d ", a[i]); //2 2 3 4 5 �� ��µ�

	/* memcpy�� ��� ���� �� ȯ�濡�� �˾Ƽ� ���۸� �Ἥ �����ϵǼ� �׷��� ��ġ�� �κ��� �־ �� �۵���
	 * but ����ȯ���� �޶����� memcpy�� �� �� ���۸� ������� �ʴ� ��쵵 ����
	 * �̷� ���� ����ؼ� ��ġ�� �κ��� �ִ� ��� ������ ���۸� ����ϴ� memmove �Լ��� ����ϴ� �� ��õ��*/
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
	
	/* str[0]�� pointer������ �ƴ϶� atoi�ϸ� ������ �߻���*/
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
		printf("�����\n");
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