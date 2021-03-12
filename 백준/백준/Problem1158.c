#include <stdio.h>
#include <stdlib.h>
struct node {
	struct node *next;
	int value;
};

struct node* Init()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->value = 1;
	temp->next = NULL;

	return temp;
}

void Insertion(struct node* ptr, int num)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->value = num;
	temp->next = NULL;

	ptr->next = temp;
}

int Remove(struct node *prev, struct node *ptr)
{
	int value = ptr->value;

	prev->next = ptr->next;
	free(ptr);

	return value;
}

int Problem1158()
{
	struct node *linked_list;
	struct node *temp, *prev;
	struct node *ptr;

	int Number_Num, step;
	int i, j, dead;

	/* �Է� ��Ʈ */
	scanf("%d %d", &Number_Num, &step);

	/* �Է� 1�� ����ó�� */
	if (Number_Num == 1) {
		printf("<1>");
		exit(0);
	}

	/* circular linked_list ���� */
	for (i = 1; i <= Number_Num; i++)
	{
		if (i == 1) {
			linked_list = Init();
			ptr = linked_list;
		}
		else {
			Insertion(ptr, i);
			ptr = ptr->next;
		}
	}
	ptr->next = linked_list;

	/* �似Ǫ�� ���� ���� */
	for (i = 1; i <= Number_Num; i++)
	{
		for (j = 0; j < step; j++)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		dead = Remove(prev, ptr);

		if (i == 1)
			printf("<%d, ", dead);
		else if (i == Number_Num)
			printf("%d>", dead);
		else
			printf("%d, ", dead);
		ptr = prev;
	}
}