#include <stdio.h>
#include <stdlib.h>

int Problem20112()
{
	char** matric;
	int size, i, j, flag = 0;

	scanf("%d", &size);


	matric = (char**)malloc(sizeof(char*) * size);
	for (i = 0; i < size; i++)
		matric[i] = (char*)malloc(sizeof(char) * size + 1);



	for (i = 0; i < size; i++)
		scanf("%s", matric[i]);

	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++)
			if (matric[i][j] != matric[j][i]) {
				flag = 1;
				break;
			}
		if (flag == 1)
			break;
	}

	if (flag == 0)
		printf("YES\n");
	else
		printf("NO\n");

	for (i = 0; i < size; i++)
		free(matric[i]);
	free(matric);
}