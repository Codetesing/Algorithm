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
	int _weight;
	int _vertex;
	struct Node* _next;
}Node;

typedef struct LIST
{
	Node* head;
	Node* tail;
}LIST;

typedef struct TOPO_SORT
{
	int _num;
	struct TOPO_SORT* _next;
}TOPO_SORT;

typedef struct QUEUE
{
	Node* front;
	Node* rear;
	int count;
}QUEUE;

TOPO_SORT* Topo_sort = NULL;

void APPEND_NODE(LIST* cur, int n)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->_next = NULL;
	temp->_vertex = n;
	temp->_weight = 1;

	if (cur->tail == NULL)
	{
		cur->head = temp;
		cur->tail = temp;
	}

	else
	{
		cur->head->_next = temp;
		cur->head = temp;
	}
}

void FREE_NODE(LIST* node)
{
	Node* temp = node->tail;
	while (temp != NULL)
	{
		node->tail = temp->_next;
		free(temp);
		temp = node->tail;
	}
	free(node);
}

void PRINT_NODE(LIST* node, int i)
{
	Node* temp = node->tail;

	printf("%d : ", i);

	while (temp != NULL)
	{
		printf("(%d %d) ", temp->_vertex, temp->_weight);
		temp = temp->_next;
	}
	printf("\n");
}

void APPEND_TOPO(int v)
{
	TOPO_SORT* temp = (TOPO_SORT*)malloc(sizeof(*temp));
	temp->_num = v;
	temp->_next = Topo_sort;
	Topo_sort = temp;
}

void TOPO_PRINT()
{
	TOPO_SORT* temp = Topo_sort;

	printf("\ntop.sort : ");

	while (temp != NULL)
	{
		printf("%d ", temp->_num);
		temp = temp->_next;
	}
	printf("\n");
}

void FREE_TOPO()
{
	TOPO_SORT* temp = Topo_sort->_next;
	while (temp != NULL)
	{
		Topo_sort->_next = temp->_next;
		free(temp);
		temp = Topo_sort->_next;
	}
	free(Topo_sort);
}

bool QUEUE_EMPTY(QUEUE *q)
{
	if (q->count == 0)
		return true;

	return false;
}

void ENQUEUE(QUEUE* q, int n)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->_vertex = n;
	cur->_next = NULL;
	cur->_weight = 0;

	if (QUEUE_EMPTY(q))
		q->front = cur;
	else
		q->rear->_next = cur;

	q->rear = cur;
	q->count++;
}

void DEQUEUE(QUEUE* q)
{
	Node* cur;

	cur = q->front;
	q->front = cur->_next;
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

void DFS_VISIT(LIST** G, int u, int* color, int*p)
{
	color[u] = GRAY;

	Node* temp = G[u]->tail;

	while (temp != NULL)
	{
		if (color[temp->_vertex] == WHITE)
		{
			p[temp->_vertex] = u;
			DFS_VISIT(G, temp->_vertex, color, p);
		}
		temp = temp->_next;
	}

	APPEND_TOPO(u);
	color[u] = BLACK;
}

void DFS_PRINT(int* p, int v)
{
	printf("\ndfs p[i] : ");
	for (int i = 1; i <= v; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void DFS(LIST** G, int v, int s)
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
			DFS_VISIT(G, u, color, p);

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

void BFS(LIST** G, int v, int s)
{
	QUEUE* queue = (QUEUE *)malloc(sizeof(QUEUE));
	Node* temp;
	int* d = NULL;
	int* p = NULL;
	int* color = NULL;
	int u = 0;

	d = (int*)malloc((v + 1) * sizeof(int));
	p = (int*)malloc((v + 1) * sizeof(int));
	color = (int*)malloc((v + 1) * sizeof(int));

	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
	INITIALIZE_SINGLE_SOURCE(d, p, color, v, s);
	color[s] = GRAY;
	ENQUEUE(queue, s);

	while (!QUEUE_EMPTY(queue))
	{
		u = queue->front->_vertex;

		temp = G[u]->tail;

		while (temp != NULL)
		{
			if (color[temp->_vertex] == WHITE)
			{
				p[temp->_vertex] = u;
				d[temp->_vertex] = d[u] + 1;
				color[temp->_vertex] = GRAY;
				ENQUEUE(queue, temp->_vertex);
			}
			temp = temp->_next;
		}

		DEQUEUE(queue);
		color[u] = BLACK;
	}

	BFS_PRINT(p, v);

	free(d);
	free(p);
	free(color);
	
	while (!QUEUE_EMPTY(queue))
		DEQUEUE(queue);
}

int main()
{
	FILE* F = NULL;
	int v, e, s, d;
	LIST** graph;

	if (!(F = fopen("input1.txt", "r")))
	{
		printf("No File!\n");
		exit(0);
	}

	fscanf(F, "%d %d", &v, &e);

	graph = (LIST**)malloc((v + 1) * sizeof(LIST*));

	for (int i = 0; i <= v; i++)
	{
		graph[i] = (LIST*)malloc(sizeof(LIST));
		graph[i]->head = NULL;
		graph[i]->tail = NULL;
	}

	for (int i = 0; i < e; i++)
	{
		fscanf(F, "%d %d", &s, &d);

		APPEND_NODE(graph[s], d);
	}

	for (int i = 1; i <= v; i++)
		PRINT_NODE(graph[i], i);

	DFS(graph,v, 1);

	BFS(graph, v, 1);

	TOPO_PRINT(Topo_sort);

	for (int i = 0; i <= v; i++)
		FREE_NODE(graph[i]);
	free(graph);

	FREE_TOPO();

	fclose(F);

	return 0;
}