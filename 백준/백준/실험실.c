#include <stdio.h>

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
		printf("½ÇÇàµÊ\n");
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