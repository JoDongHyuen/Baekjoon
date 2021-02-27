#include <stdio.h>
/* 스택 문제는 항상 push 혹은 pop을 할 때 어떤 조건에서 행해야할지 잘 고민해야 함*/

long long int result = 0; // result 결과가 좀 클 거 같다 싶으면 lld로 선언하라!!
int Problem6198_Stack[80001];
int Problem6198_Top = 0; // 1 - indexed로 접근함

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

	/* 입력 파트 */
	scanf("%d", &Buliding_Num);
	for (i = 1; i <= Buliding_Num; i++)
	{
		scanf("%d", &Height_Input);
		Problem6198_push(Height_Input);
	}

	/* 스택 나머지 요소 처리 파트 */
	if (Problem6198_Top != 0)
	{
		for (i = 0; i < Problem6198_Top;)
		{
			Problem6198_pop();
			result += Problem6198_Top;
		}
	}

	/* 출력 파트 */
	printf("%lld\n", result);
}