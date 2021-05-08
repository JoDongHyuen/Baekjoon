#include <stdio.h>

int queue[2501];
int Schedule[51][51];
int People[51];
int Visit[51];
int Network[51][51];
int Party_Num, People_Num;
int Know_True;
int front, rear;

void push(int idx)
{
	queue[rear++] = idx;
}

int pop()
{
	return queue[front++];
}

void BFS(int idx)
{
	int i, src;
	push(idx);
	Visit[idx] = 1;

	while (front != rear)
	{
		src = pop();
		for (i = 1; i <= People_Num; i++) {
			if (Visit[i] == 1) continue;
			if (Network[src][i] == 0) continue;
			Visit[i] = 1;
			push(i);
		}
	}
}

int Problem1043()
{
	int i, j, k, People_Idx, Join_Num;
	int count = 0;
	scanf("%d %d", &People_Num, &Party_Num);
	scanf("%d", &Know_True);

	for (i = 0; i < Know_True; i++)
	{
		scanf("%d", &People_Idx);
		People[i] = People_Idx;
	}
	
	/* ��Ƽ ���� ���� */
	for (i = 1; i <= Party_Num; i++)
	{
		scanf("%d", &Join_Num);
		Schedule[i][0] = Join_Num;
		for (j = 1; j <= Join_Num; j++)
		{
			scanf("%d", &People_Idx);
			Schedule[i][People_Idx] = 1;
		}
	}

	/* ������ ��Ƽ ������ ���� ������ ��� ���� �׷��� ���� */
	for (i = 1; i <= Party_Num; i++)
		for (j = 1; j <= People_Num; j++)
			for (k = j; k <= People_Num; k++)
				if (Schedule[i][j] == 1 && Schedule[i][k] == 1)
				{
					Network[j][k] = 1;
					Network[k][j] = 1;
				}

	/* �׷��� BFS�� ����� �� �ϸ� �ȵǴ� ��� ���� */
	for (i = 0; i < Know_True; i++)
		if (Visit[People[i]] == 0)
			BFS(People[i]);

	/* ��� ��� */
	if (Know_True == 0)
		printf("%d", Party_Num);
	else
	{
		int flag;

		/* ��Ƽ�� ������ �ƴ� ���, ���ǰ� ����� �̾߱⸦ ���� �� �ִ� ��� üũ*/
		for (i = 1; i <= Party_Num; i++) {
			flag = 1;
			for (j = 1; j <= People_Num; j++)
				if (Schedule[i][j] == 1 && Visit[j] == 1) {
					flag = 0;
					break;
				}
			if (flag == 0)
				continue;
			count++;
		}

		printf("%d", count);
	}
}