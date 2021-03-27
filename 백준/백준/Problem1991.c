#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char Data;
	struct _node *Left;
	struct _node *Right;
}Node;


void preorder(Node* root)
{
	if (root != NULL) {
		printf("%c", root->Data);
		preorder(root->Left);
		preorder(root->Right);
	}
}

void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->Left);
		printf("%c", root->Data);
		inorder(root->Right);
	}
}

void postorder(Node* root)
{
	if (root != NULL) {
		postorder(root->Left);
		postorder(root->Right);
		printf("%c", root->Data);
	}
}

void freetree(Node* root)
{
	if (root != NULL) {
		freetree(root->Left);
		freetree(root->Right);
		free(root);
	}
}

Node* Find_Node(Node* tree, char data)
{
	Node* result = NULL;
	if (tree != NULL) {
		if (tree->Data == data)
			return tree;
		else {
			if (result == NULL)
				result = Find_Node(tree->Left, data);
			if (result == NULL)
				result = Find_Node(tree->Right, data);
		}
		return result;
	}
	else
		return NULL;

}

void Tree_Insert(Node* Root, char data, char left, char right)
{
	Node* target, *Left_Temp, *Right_Temp;
	target = Find_Node(Root, data);

	if (left != '.') {
		Left_Temp = (Node*)malloc(sizeof(Node));
		Left_Temp->Data = left;
		Left_Temp->Left = NULL;
		Left_Temp->Right = NULL;
		target->Left = Left_Temp;
	}
	else
		target->Left = NULL;

	if (right != '.') {
		Right_Temp = (Node*)malloc(sizeof(Node));
		Right_Temp->Data = right;
		Right_Temp->Left = NULL;
		Right_Temp->Right = NULL;
		target->Right = Right_Temp;
	}
	else
		target->Right = NULL;

}

Node* Tree_Init(char data, char left, char right)
{
	Node *Temp, *Left_Temp, *Right_Temp;
	Temp = (Node*)malloc(sizeof(Node));

	Temp->Data = data;

	if (left != '.') {
		Left_Temp = (Node*)malloc(sizeof(Node));
		Left_Temp->Data = left;
		Left_Temp->Left = NULL;
		Left_Temp->Right = NULL;
		Temp->Left = Left_Temp;
	}
	else
		Temp->Left = NULL;

	if (right != '.') {
		Right_Temp = (Node*)malloc(sizeof(Node));
		Right_Temp->Data = right;
		Right_Temp->Left = NULL;
		Right_Temp->Right = NULL;
		Temp->Right = Right_Temp;
	}
	else
		Temp->Right = NULL;

	return Temp;
}

int Problem1991()
{
	int Node_Num;
	int i;
	char Input_Data, Input_Left, Input_Right;
	Node* Root = NULL;

	scanf("%d", &Node_Num);

	for (i = 0; i < Node_Num; i++)
	{
		getchar();
		scanf("%c %c %c", &Input_Data, &Input_Left, &Input_Right);
		if (Root == NULL)
			Root = Tree_Init(Input_Data, Input_Left, Input_Right);
		else
			Tree_Insert(Root, Input_Data, Input_Left, Input_Right);
	}

	preorder(Root);
	printf("\n");
	inorder(Root);
	printf("\n");
	postorder(Root);
	printf("\n");
	freetree(Root);
}