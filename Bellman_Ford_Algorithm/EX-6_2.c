#define _CRT_SECURE_NO_WARNINGS

#define NIL -1
#define INFINITY 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <stdio.h>
#include <stdlib.h>

typedef struct BLOCK {
	int _s;
	int _h;
	int _w;
}BLOCK;

typedef struct NODE {
	int _v;
	int _h;
	struct NODE* next;
}NODE;

typedef struct LIST {
	NODE* head;
	NODE* tail;
}LIST;

typedef struct TOPO_SORT
{
	int _num;
	struct TOPO_SORT* _next;
}TOPO_SORT;

TOPO_SORT* Topo_sort = NULL;

void APPEND_NODE(LIST* cur, int h, int n)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));

	temp->next = NULL;
	temp->_h = h;
	temp->_v = n;

	if (cur->tail == NULL)
	{
		cur->head = temp;
		cur->tail = temp;
	}

	else
	{
		cur->head->next = temp;
		cur->head = temp;
	}
}

void FREE_NODE(LIST* node)
{
	NODE* temp = node->tail;

	while (temp != NULL)
	{
		node->tail = temp->next;
		free(temp);
		temp = node->tail;
	}
	free(node);
}

void MAKE_LIST(LIST** graph, BLOCK* block, int n)
{
	for (int i = 1; i <= n; i++)
		APPEND_NODE(graph[0], 0, i);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			if ((block[i]._s < block[j]._s) || (block[i]._w < block[j]._w))
				continue;

			APPEND_NODE(graph[i], block[i]._h, j);
		}
		APPEND_NODE(graph[i], block[i]._h, n + 1);
	}
}

void APPEND_TOPO(int v)
{
	TOPO_SORT* temp = (TOPO_SORT*)malloc(sizeof(*temp));
	temp->_num = v;
	temp->_next = Topo_sort;
	Topo_sort = temp;
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

void INITIALIZE_SINGLE_SOURCE(int* d, int* p, int* color, int v, int s)
{
	for (int i = 0; i <= v + 1; i++)
	{
		d[i] = 0;
		p[i] = NIL;
		color[i] = WHITE;
	}
}

void RELAX(NODE* node, int* d, int* p, int u)
{
	NODE* temp = node;

	while (temp != NULL)
	{
		if (d[temp->_v] < (d[u] + temp->_h))
		{
			d[temp->_v] = d[u] + temp->_h;
			p[temp->_v] = u;
		}
		temp = temp->next;
	}
}

// TOWER_NUM 두번 안돌리고 한번에 구하는법.

int TOWER_NUM(int* p, int n)
{
	if (p[n] == 0)
		return 0;

	return TOWER_NUM(p, p[n]) + 1;
}

void PRINT_TOWER(int* p, int n)
{
	if (p[n] == 0)
		return;

	printf("%d\n", p[n]);

	PRINT_TOWER(p, p[n]);
}

// DFS function

void DFS_VISIT(LIST** G, int u, int* color, int* p)
{
	color[u] = GRAY;

	NODE* temp = G[u]->tail;

	while (temp != NULL)
	{
		if (color[temp->_v] == WHITE)
		{
			p[temp->_v] = u;
			DFS_VISIT(G, temp->_v, color, p);
		}
		temp = temp->next;
	}

	APPEND_TOPO(u);
	color[u] = BLACK;
}

void DFS(LIST** G, int n, int s)
{
	int* d = NULL;
	int* p = NULL;
	int* visit = NULL;

	d = (int*)malloc((n + 2) * sizeof(int));
	p = (int*)malloc((n + 2) * sizeof(int));
	visit = (int*)malloc((n + 2) * sizeof(int));

	INITIALIZE_SINGLE_SOURCE(d, p, visit, n, s);

	for (int u = 0; u <= n + 1; u++)
		if (visit[u] == WHITE)
			DFS_VISIT(G, u, visit, p);

	// TOPO_SORT 순서대로 RELAX

	for (TOPO_SORT* temp = Topo_sort; temp != NULL; temp = temp->_next)
		RELAX(G[temp->_num]->tail, d, p, temp->_num);

	printf("%d\n", TOWER_NUM(p, n + 1));
	PRINT_TOWER(p, n + 1);
	printf("height : %d\n", d[n + 1]);

	free(d);
	free(p);
	free(visit);
}

int main()
{
	FILE* F;
	LIST** GRAPH;
	BLOCK* block;
	int N = 0;

	if (!(F = fopen("input.txt", "r")))
	{
		printf("No FILE!\n");
		exit(0);
	}

	fscanf(F, "%d", &N);

	GRAPH = (LIST**)malloc((N + 2) * sizeof(LIST*));
	for (int i = 0; i <= N + 1; i++)
	{
		GRAPH[i] = (LIST*)malloc(sizeof(LIST));
		GRAPH[i]->head = NULL;
		GRAPH[i]->tail = NULL;
	}

	block = (BLOCK*)malloc((N + 1) * sizeof(BLOCK));

	for (int i = 1; i <= N; i++)
		fscanf(F, "%d %d %d", &block[i]._s, &block[i]._h, &block[i]._w);

	MAKE_LIST(GRAPH, block, N);

	DFS(GRAPH, N, 0);

	for (int i = 0; i <= N + 1; i++)
		FREE_NODE(GRAPH[i]);
	free(GRAPH);

	FREE_TOPO();

	free(block);

	fclose(F);

	return 0;
}