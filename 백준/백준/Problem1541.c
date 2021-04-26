#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[51];

int Problem1541()
{
	char *p, *s;
	int i, len;
	int sum = 0, flag = 0;
	scanf("%s", input);

	p = input;
	len = strlen(input);

	for (i = 0; i < len; i++)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			if (flag == 0 && input[i] == '+')
			{
				input[i] = '\0';
				sum += atoi(p);
				p = &(input[i]) + 1;
			}
			else if(flag == 0 && input[i] == '-')
			{
				flag = 1;
				input[i] == '\0';
				sum += atoi(p);
				p = &(input[i]) + 1;
			}
			else
			{
				input[i] == '\0';
				sum -= atoi(p);
				p = &(input[i]) + 1;
			}
		}
	}

	if (flag == 0)
		sum += atoi(p);
	else
		sum -= atoi(p);

	printf("%d\n", sum);
}