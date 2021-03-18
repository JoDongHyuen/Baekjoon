#include <stdio.h>
#include <string.h>

char Enc[100000][21];
char check[21];
int Problem1620()
{
	int Pok_Num, Problem_Num;
	int i, j, num;

	scanf("%d%d", &Pok_Num, &Problem_Num);
	for (i = 0; i < Pok_Num; i++)
		scanf("%s", Enc[i]);

	for (i = 0; i < Problem_Num; i++) {
		scanf("%s", check);
		if (check[0] >= 'A') {
			for (j = 0; j < Pok_Num; j++)
				if (strcmp(check, Enc[j]) == 0)
				{
					printf("%d\n", j + 1);
					break;
				}
		}
		else
		{
			num = atoi(check);
			printf("%s\n", Enc[num - 1]);
		}
				
	}
}