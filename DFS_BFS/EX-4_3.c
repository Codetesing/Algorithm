#define _CRT_SECURE_NO_WARNINGS

#define NIL -1
#define INFINITY 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	struct Node* head;
	int _weight;
	int _vertex;
	struct Node* tail;
}Node;

typedef struct QUEUE
{
	Node* front;
	Node* rear;
	int count;
}QUEUE;

void APPEND_NODE(Node* cur, int n)
{
	Node* temp;

	if (cur->tail == NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->head = NULL;
		temp->tail = NULL;
		temp->_vertex = n;
		temp->_weight = 1;

		cur->head = temp;
		cur->tail = temp;
	}

	else
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->head = cur->head;
		temp->tail = NULL;
		temp->_vertex = n;
		temp->_weight = 1;

		cur->head->tail = temp;
		cur->head = temp;
	}
}

void FREE_NODE(Node* node)
{
	Node* temp = node->tail;

	while (temp != NULL)
	{
		node->tail = temp->tail;
		free(temp);
		temp = node->tail;
	}
	free(node);
}

void PRINT_NODE(Node* node, int i)
{
	Node* temp = node->tail;

	printf("%d : ", i);

	while (temp != NULL)
	{
		printf("(%d %d) ", temp->_vertex, temp->_weight);
		temp = temp->tail;
	}
	printf("\n");
}

bool QUEUE_EMPTY(QUEUE *q)
{
	if (q->count == 0)
		return true;

	return false;
}

void ENQUEUE(QUEUE *q, int n)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->_vertex = n;
	cur->head = NULL;
	cur->tail = NULL;
	cur->_weight = 0;

	if (QUEUE_EMPTY(q))
		q->front = cur;
	else
		q->rear->tail = cur;

	q->rear = cur;
	q->count++;
}

void DEQUEUE(QUEUE* q)
{
	Node* cur;

	cur = q->front;
	q->front = cur->tail;
	free(cur);
	q->count--;
}

void INITIALIZE_SINGLE_SOURCE(int* d, int* p, int* color, int v, int s)
{
	for (int i = 1; i <= v; i++)
	{
		d[i] = INFINITY;
		p[i] = NIL;
		color[i] = WHITE;
	}
	d[s] = 0;
}

	//**************** DFS_SEARCH **********************

void DFS_VISIT(Node** G, int u, int* color, int*p, Node* topo_sort)
{
	color[u] = GRAY;

	Node* temp = G[u]->tail;

	while (temp != NULL)
	{
		if (color[temp->_vertex] == WHITE)
		{
			p[temp->_vertex] = u;
			DFS_VISIT(G, temp->_vertex, color, p, topo_sort);
		}
		temp = temp->tail;
	}

	APPEND_NODE(topo_sort, u);
	color[u] = BLACK;
}

void DFS_PRINT(int* p, int v)
{
	printf("\ndfs p[i] : ");
	for (int i = 1; i <= v; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void TOPO_PRINT(Node* node)
{
	Node* temp = node->head;

	printf("\ntop.sort : ");

	while (temp != NULL)
	{
		printf("%d  ", temp->_vertex);
		temp = temp->head;
	}
	printf("\n");
}

void DFS(Node** G, Node* topo_sort, int v, int s)
{
	int* d = NULL;
	int* p = NULL;
	int* color = NULL;

	d = (int*)malloc((v + 1) * sizeof(int));
	p = (int*)malloc((v + 1) * sizeof(int));
	color = (int*)malloc((v + 1) * sizeof(int));

	INITIALIZE_SINGLE_SOURCE(d, p, color, v, s);

	for (int u = 1; u <= v; u++)
		if (color[u] == WHITE)
			DFS_VISIT(G, u, color, p, topo_sort);

	DFS_PRINT(p, v);

	free(d);
	free(p);
	free(color);
}

	//**************** BFS_SEARCH **********************

void BFS_PRINT(int* p, int v)
{
	printf("bfs p[i] : ");
	for (int i = 1; i <= v; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void BFS(Node** G, int v, int s)
{
	QUEUE queue;
	Node* temp;
	int* d = NULL;
	int* p = NULL;
	int* color = NULL;
	int u = 0;

	d = (int*)malloc((v + 1) * sizeof(int));
	p = (int*)malloc((v + 1) * sizeof(int));
	color = (int*)malloc((v + 1) * sizeof(int));

	queue.front = NULL;
	queue.rear = NULL;
	queue.count = 0;
	INITIALIZE_SINGLE_SOURCE(d, p, color, v, s);
	color[s] = GRAY;
	ENQUEUE(&queue, s);

	while (!QUEUE_EMPTY(&queue))
	{
		u = queue.front->_vertex;

		temp = G[u]->tail;

		while (temp != NULL)
		{
			if (color[temp->_vertex] == WHITE)
			{
				p[temp->_vertex] = u;
				d[temp->_vertex] = d[u] + 1;
				color[temp->_vertex] = GRAY;
				ENQUEUE(&queue, temp->_vertex);
			}
			temp = temp->tail;
		}

		DEQUEUE(&queue);

		color[u] = BLACK;
	}

	BFS_PRINT(p, v);

	free(d);
	free(p);
	free(color);
	
	while (!QUEUE_EMPTY(&queue))
		DEQUEUE(&queue);
}

int main()
{
	FILE* F = NULL;
	int v, e, s, d;
	Node** graph;
	Node* Topo_sort = NULL;

	if (!(F = fopen("input1.txt", "r")))
	{
		printf("No File!\n");
		exit(0);
	}

	fscanf(F, "%d %d", &v, &e);

	graph = (Node**)malloc((v + 1) * sizeof(Node*));
	Topo_sort = (Node*)malloc(sizeof(Node));
	Topo_sort->head = NULL;
	Topo_sort->tail = NULL;
	for (int i = 0; i <= v; i++)
	{
		graph[i] = (Node*)malloc(sizeof(Node));
		graph[i]->head = NULL;
		graph[i]->tail = NULL;
	}

	for (int i = 0; i < e; i++)
	{
		fscanf(F, "%d %d", &s, &d);

		APPEND_NODE(graph[s], d);
	}

	for (int i = 1; i <= v; i++)
	{
		PRINT_NODE(graph[i], i);
	}

	DFS(graph, Topo_sort, v, 1);

	BFS(graph, v, 1);

	TOPO_PRINT(Topo_sort);

	for (int i = 0; i <= v; i++)
	{
		FREE_NODE(graph[i]);
	}
	free(graph);
	FREE_NODE(Topo_sort);

	fclose(F);

	return 0;
}