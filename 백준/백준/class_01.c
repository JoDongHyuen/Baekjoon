//solved.ac�� class1�� �ش��ϴ� ������
//�ܰ躰�� Ǯ���� ��ġ�� ������ �������� ����
#include <stdio.h>
#include <stdbool.h>

int class1Problem2()
{
	int i, j, input;
	bool is_ascend = true, is_decend = true;

	j = 8;
	for (i = 1; i <= 8; i++) {
		scanf("%d", &input);
		
		if (input != i)
			is_ascend = false;

		if (input != j)
			is_decend = false;
		j--;
	}

	if (is_ascend == false && is_decend == false)
		printf("mixed\n");
	
	else if (is_ascend == true)
		printf("ascending\n");
	
	else if (is_decend == true)
		printf("descending\n");
}

int class1Problem1()
{
	int sum, input;
	int i;
	sum = 0;

	for (i = 0; i < 5; i++) {
		scanf(" %d", &input);
		sum = sum + input * input;
	}

	printf("%d\n", sum % 10);
}