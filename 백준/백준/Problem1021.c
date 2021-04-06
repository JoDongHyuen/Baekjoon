#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	struct _node *front;
	struct _node *back;
}Node;

Node* Init()
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = 1;
	temp->front = NULL;
	temp->back = NULL;

	return temp;
}

void Insert(Node* Last, int value)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->front = Last;
	temp->back = NULL;
	Last->back = temp;
}

Node* Del(Node* Target, Node* Target_Front)
{
	if (Target == Target_Front)
	{
		free(Target);
		return NULL;
	}
	else
	{
		Target_Front->back = Target->back;
		Target->back->front = Target_Front;
		free(Target);

		return Target_Front->back;
	}
}

int Find2Right(Node** Now, int target)
{
	int count = 0;
	while ((*Now)->value != target)
	{
		(*Now) = (*Now)->back;
		count++;
	}

	return count;
}

int Find2Left(Node** Now, int target)
{
	int count = 0;
	while ((*Now)->value != target)
	{
		(*Now) = (*Now)->front;
		count++;
	}

	return count;
}

int Problem1021()
{
	Node* List = NULL;
	Node* Last = NULL;
	int N, M, result = 0;
	int i, target;

	/* 연결 리스트 생성 */
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		if (List == NULL) {
			List = Init();
			Last = List;
		}
		else {
			Insert(Last, i);
			Last = Last->back;
		}
	}
	Last->back = List;
	List->front = Last;

	/* 큐가 회전합니다~ */
	for (i = 0; i < M; i++)
	{
		scanf("%d", &target);
		if (List->value == target)
		{
			List = Del(List, List->front);
		}
		else
		{
			Node* Right = List;
			Node* Left = List;
			int count_right = Find2Right(&Right, target);
			int count_left = Find2Left(&Left, target);

			if (count_left > count_right) {
				List = Del(Right, Right->front);
				result += count_right;
			}
			else
			{
				List = Del(Left, Left->front);
				result += count_left;
			}
		}
	}
	printf("%d\n", result);

	/* 동적 할당 해제 */
	while (List)
		List = Del(List, List->front);
}