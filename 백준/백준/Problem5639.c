#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	struct _node *left;
	struct _node *right;
}Node;

Node* Init(int num)
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->value = num;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void postorder(Node* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->value);
		free(root);
	}
}

void Insert(Node* root, int num)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = num;
	temp->left = NULL;
	temp->right = NULL;

	while (1)
	{
		if (root->value > temp->value)
		{
			if (root->left != NULL) {
				root = root->left;
				continue;
			}
			else{
				root->left = temp;
				break;
			}
		}
		else if (root->value < temp->value)
		{
			if (root->right != NULL) {
				root = root->right;
				continue;
			}
			else {
				root->right = temp;
				break;
			}
		}
	}
}

int Problem5639()
{
	int input;
	Node* root = NULL;
	
	while (scanf("%d", &input) != EOF)
	{
		if (root == NULL)
			root = Init(input);//Init
		else
			Insert(root, input);//Insert
	}

	postorder(root);
	
}