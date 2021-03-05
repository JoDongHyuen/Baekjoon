#include <stdio.h>
#include <string.h>

int Problem9012()
{
	int Test_Case, i, j, len;
	int Oper_Count;
	char input[51];

	scanf("%d", &Test_Case);
	for (i = 0; i < Test_Case; i++)
	{
		scanf("%s", input);
		len = strlen(input);
		Oper_Count = 0;
		for (j = 0; j < len; j++) {
			if (input[j] == '(')
				Oper_Count++;
			else
				Oper_Count--;
			if (Oper_Count < 0)
				break;
		}
		if (Oper_Count == 0)
			printf("YES\n");
		else
			printf("NO\n");

	}
}