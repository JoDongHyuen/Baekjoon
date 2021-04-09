#include <stdio.h>
#include <stdlib.h>

typedef struct _pair {
	int value;
	int index;
}Pair;

Pair In_Order[100001];
Pair temp[100001];
int Post_Order[100001] = { 0 };
int Last_Pos;

typedef struct _node {
	int value;
	struct _node* left;
	struct _node* right;
}Node;

Node* Find_Tree(int start, int end)
{
	if (start > end)
		return NULL;
	else
	{
		Node* node = (Node*)malloc(sizeof(Node));
		int i, target, flag = 0;
		int low = start, high = end;
		int mid;
		target = Post_Order[Last_Pos];
		/*
		for (i = start; i <= end; i++)
			if (In_Order[i] == target) {
				Last_Pos--;
				flag = 1;
				break;
			}//이 부분이 시간 초과인거 같은데;;
		//구조체 index , value 넣고 정렬, 이진탐색?
		*/

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (In_Order[mid].value < target) {
				low = mid + 1;
				continue;
			}
			else if (In_Order[mid].value > target) {
				high = mid - 1;
				continue;
			}
			else {
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			return NULL;

		node->value = target;
		node->right = Find_Tree(In_Order[mid].index + 1, end);
		node->left = Find_Tree(start, In_Order[mid].index - 1);

		return node;
	}
}

void Pre_Order(Node* root)
{
	if (root)
	{
		printf("%d ", root->value);
		Pre_Order(root->left);
		Pre_Order(root->right);
	}
}

void Free_Tree(Node* root)
{
	if (root)
	{
		Free_Tree(root->left);
		Free_Tree(root->right);
		free(root);
	}
}

void Merge_Sort(int start, int mid, int end)
{
	int Main_Idx = start, Idx1 = start, Idx2 = mid;
	int i;

	for (i = start; i <= end; i++)
		temp[i] = In_Order[i];

	while (Idx1 <= (mid - 1) && Idx2 <= end)
	{
		if (temp[Idx1].value <= temp[Idx2].value)
			In_Order[Main_Idx++] = temp[Idx1++];
		else
			In_Order[Main_Idx++] = temp[Idx2++];
	}

	if (Idx1 < mid)
		for (i = 0; i < (mid - Idx1); i++)
			In_Order[Main_Idx + i] = temp[Idx1 + i];
}

void Merge(int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Merge(start, mid);
		Merge(mid + 1, end);
		Merge_Sort(start, mid + 1, end);
	}
}

int Problem2263()

{
	int Node_Num, i;
	Node* Root = NULL;

	scanf("%d", &Node_Num);
	Last_Pos = Node_Num - 1;

	for (i = 0; i < Node_Num; i++) {
		scanf("%d", &In_Order[i].value);
		In_Order[i].index = i;
	}
	for (i = 0; i < Node_Num; i++)
		scanf("%d", &Post_Order[i]);

	Merge(0, Node_Num - 1);

	Root = Find_Tree(0, Node_Num - 1);

	Pre_Order(Root);
	Free_Tree(Root);
}