#include <stdio.h>
/* ���� ������ �׻� push Ȥ�� pop�� �� �� � ���ǿ��� ���ؾ����� �� ����ؾ� ��*/

long long int result = 0; // result ����� �� Ŭ �� ���� ������ lld�� �����϶�!!
int Problem6198_Stack[80001];
int Problem6198_Top = 0; // 1 - indexed�� ������

/* stack pop */
void Problem6198_pop()
{
	Problem6198_Top--;
}

/* stack push */
void Problem6198_push(int Height)
{
	int i, Num;
	if (Problem6198_Top == 0 || Problem6198_Stack[Problem6198_Top] > Height )
		Problem6198_Stack[++Problem6198_Top] = Height;
	else
	{
		Num = Problem6198_Top;
		for (i = 0; i < Num; i++) {
			if (Problem6198_Stack[Problem6198_Top] <= Height) {
				Problem6198_pop();
				result += Problem6198_Top;
			}
			else {
				Problem6198_Stack[++Problem6198_Top] = Height;
				break;
			}
		}
		if (Problem6198_Top == 0)
			Problem6198_Stack[++Problem6198_Top] = Height;
	}
}

int Problem6198()
{
	int Buliding_Num;
	int i, Height_Input;

	/* �Է� ��Ʈ */
	scanf("%d", &Buliding_Num);
	for (i = 1; i <= Buliding_Num; i++)
	{
		scanf("%d", &Height_Input);
		Problem6198_push(Height_Input);
	}

	/* ���� ������ ��� ó�� ��Ʈ */
	if (Problem6198_Top != 0)
	{
		for (i = 0; i < Problem6198_Top;)
		{
			Problem6198_pop();
			result += Problem6198_Top;
		}
	}

	/* ��� ��Ʈ */
	printf("%lld\n", result);
}