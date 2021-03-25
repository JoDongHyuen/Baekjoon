#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Problem5582()
{
	char input1[4001], input2[4001];
	int **DP;
	int endpos;
	int len1, len2, i, j, max = 0;

	scanf("%s%s", input1, input2);
	len1 = strlen(input1);
	len2 = strlen(input2);

	DP = (int**)malloc(sizeof(int*) * len2);
	for (i = 0; i < len2; i++)
		DP[i] = (int*)malloc(sizeof(int) * len1);

	for (j = 0; j < len2; j++)
		if (input1[0] == input2[j])
			DP[j][0] = 1;
		else
			DP[j][0] = 0;

	for (i = 0; i < len1; i++)
		if (input1[i] == input2[0])
			DP[0][i] = 1;
		else
			DP[0][i] = 0;

	for (i = 1; i < len1; i++)
	{
		for (j = 1; j < len2; j++)
		{
			if (input1[i] == input2[j])
				DP[j][i] = DP[j - 1][i - 1] + 1;
			else
				DP[j][i] = 0;

			if (DP[j][i] > max)
				max = DP[j][i], endpos = i;
		}
	}
	//for (i = max - 1; i >= 0; i--)
	//	printf("%c", input1[endpos - i]);
	//printf("\n");
	printf("%d\n", max);
}