#include <stdio.h>
#include <string.h>

int Problem2902()
{
	char input[101];
	int i, len;
	
	scanf("%s", input);
	len = strlen(input);

	printf("%c", input[0]);

	for (i = 0; i < len; i++)
		if (input[i] == '-')
			printf("%c", input[i + 1]);
	printf("\n");
}