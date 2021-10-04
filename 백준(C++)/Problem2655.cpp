#include<iostream>
#include<fstream>
#define WHITE 2
#define GRAY 3
#define BLACK 5
using namespace std;

struct Node
{
	Node* next;
	int vertex;
	int weight;
};

class LinkedList
{
public:
	void print();
	void push(int, int);
	void push(int);
	void push_front(int, int);
	Node* pop();
	Node* header = NULL;
	Node* tail = NULL;
};

void LinkedList::push(int vertex)
{
	Node* temp = new Node;
	temp->next = NULL;
	temp->vertex = vertex;

	if (header == NULL)
	{
		header = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}

void LinkedList::push(int vertex, int weight)
{
	Node* temp = new Node;
	temp->next = NULL;
	temp->vertex = vertex;
	temp->weight = weight;

	if (header == NULL)
	{
		header = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}

void LinkedList::push_front(int vertex, int weight)
{
	Node* temp = new Node;
	temp->next = header;
	temp->vertex = vertex;
	header = temp;
}

Node* LinkedList::pop()
{
	Node *temp = header;

	if (header != NULL)
		header = header->next;

	return temp;
}

void LinkedList::print()
{
	Node* temp = header;
	while (temp != NULL)
	{
		cout << "( " << temp->vertex << " " << temp->weight << " ) ";
		temp = temp->next;
	}
	cout << "\n";
}

class Graph
{
public:
	int vertices;
	int edges;
	int *d;
	int *p;
	int *color;
};

void Initialize_Single_Source(Graph* G, int s)
{
	int size = G->vertices;

	G->d = new int[size + 2];
	G->p = new int[size + 2];
	G->color = new int[size + 2];

	for (int i = 0; i <= size + 1; i++) {
		G->d[i] = 0;
		G->p[i] = 0;
	}
}

void DFS_visit(int u, Graph* G, LinkedList* Adj, LinkedList* result) {

	Node* temp = Adj[u].header;
	int v;

	G->color[u] = GRAY;
	while (temp != NULL)
	{
		v = temp->vertex;
		if (G->color[v] == WHITE) {
			G->p[v] = u;
			DFS_visit(v, G, Adj, result);
		}
		temp = temp->next;
	}

	result->push_front(u, -1);
	G->color[u] = BLACK;
}

void DFS(Graph* G, LinkedList* Adj, LinkedList* result) {
	int u;
	for (u = 0; u < G->vertices; u++)
	{
		G->color[u] = WHITE;
		G->p[u] = -1;
	}

	for (u = 0; u < G->vertices; u++)
		if (G->color[u] == WHITE)
			DFS_visit(u, G, Adj, result);
}

LinkedList* Topological_Sort(Graph* G, LinkedList* Adj) {
	LinkedList* temp = new LinkedList;

	DFS(G, Adj, temp);

	return temp;
}

void RELAX(Graph* G, int u, int v, int W)
{
	if (G->d[v] < G->d[u] + W)
	{
		G->d[v] = G->d[u] + W;
		G->p[v] = u;
	}
}

int count_block(Graph* G, int vertex)
{
	int count = 0;

	while (G->p[vertex] != 0)
	{
		count++;
		vertex = G->p[vertex];
	}

	return count;
}

void print_block(Graph* G, int vertex)
{
	if (G->p[vertex] != 0)
	{
		cout << G->p[vertex] << "\n";
		print_block(G, G->p[vertex]);
	}
}

struct block {
	int weight;
	int area;
	int height;
};

int main()
{
	LinkedList *Adjacent_List;
	LinkedList *result;
	Node* temp;
	Node* edges;
	Graph *G;
	block *blocks;
	int block_num;
	int i, j;


	cin >> block_num;
	blocks = new block[block_num + 1];
	Adjacent_List = new LinkedList[block_num + 2];
	G = new Graph;
	G->vertices = block_num + 2;
	G->edges = 0;

	for (i = 1; i <= block_num; i++)
		cin >> blocks[i].area >> blocks[i].height >> blocks[i].weight;

	
	/* Create Graph with Adj list */

	// from single source to all vertex
	for (i = 1; i <= block_num; i++)
	{
		Adjacent_List[0].push(i, 0);
		G->edges++;
	}
	// from vertex to vertex
	for (i = 1; i < block_num; i++)
		for (j = i + 1; j <= block_num; j++)
		{
			if (blocks[i].weight > blocks[j].weight && blocks[i].area > blocks[j].area)
			{
				Adjacent_List[i].push(j, blocks[i].height);
				G->edges++;
			}
			else if (blocks[i].weight < blocks[j].weight && blocks[i].area < blocks[j].area)
			{
				Adjacent_List[j].push(i, blocks[j].height);
				G->edges++;
			}
		}
	// from all vertex to destination
	for (i = 1; i <= block_num; i++)
	{
		Adjacent_List[i].push(block_num + 1, blocks[i].height);
		G->edges++;
	}

	/* Typological Sort */
	Initialize_Single_Source(G, block_num);
	result = Topological_Sort(G, Adjacent_List);

	/* RELAX Process */
	temp = result->header;
	while (temp != NULL) {
		edges = Adjacent_List[temp->vertex].header;
		while (edges != NULL) {
			RELAX(G, temp->vertex, edges->vertex, edges->weight);
			edges = edges->next;
		}
		temp = temp->next;
	}

	cout << count_block(G, block_num + 1) << "\n";
	print_block(G, block_num + 1);
}