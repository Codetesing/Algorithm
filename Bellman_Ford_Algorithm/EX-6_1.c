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
	int _n;
	struct BLOCK* next;
}BLOCK;

typedef struct NODE {
	BLOCK* head;
	BLOCK* tail;
}NODE;

void APPEND_NODE(NODE* cur, int s, int h, int w, int n)
{
	BLOCK* temp = (BLOCK*)malloc(sizeof(BLOCK));

	if (cur->tail == NULL)
	{
		temp->next = NULL;
		temp->_s = s;
		temp->_h = h;
		temp->_w = w;
		temp->_n = n;

		cur->head = temp;
		cur->tail = temp;
	}

	else
	{
		temp->next = NULL;
		temp->_s = s;
		temp->_h = h;
		temp->_w = w;
		temp->_n = n;

		cur->head->next = temp;
		cur->head = temp;
	}
}

void FREE_NODE(NODE* node)
{
	BLOCK* temp = node->tail;

	while (temp != NULL)
	{
		node->tail = temp->next;
		free(temp);
		temp = node->tail;
	}
	free(node);
}

void MAKE_LIST(NODE** graph, BLOCK* block, int n)
{
	for (int i = 1; i <= n; i++)
		APPEND_NODE(graph[0], 0, 0, 0, i);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			if ((block[i]._s < block[j]._s) || (block[i]._w < block[j]._w))
				continue;

			APPEND_NODE(graph[i], block[j]._s, block[i]._h, block[j]._w, j);
		}
		APPEND_NODE(graph[i], 0, block[i]._h, 0, n + 1);
	}
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

void RELAX(NODE* node, int* d, int* p, int i)
{
	BLOCK* temp = node->tail;

	while (temp != NULL)
	{
		if (d[temp->_n] < (d[i] + temp->_h))
		{
			d[temp->_n] = d[i] + temp->_h;
			p[temp->_n] = i;
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

void DFS_VISIT(NODE** G, int u, int* color, int* p, NODE* topo_sort)
{
	color[u] = GRAY;

	BLOCK* temp = G[u]->tail;

	while (temp != NULL)
	{
		if (color[temp->_n] == WHITE)
		{
			p[temp->_n] = u;
			DFS_VISIT(G, temp->_n, color, p, topo_sort);
		}
		temp = temp->next;
	}

	APPEND_NODE(topo_sort, 0, 0, 0, u);
	color[u] = BLACK;
}

void DFS(NODE** G, int n, int s, NODE* topo_sort)
{
	int* d = NULL;
	int* p = NULL;
	int* visit = NULL;
	int* topo = NULL;

	d = (int*)malloc((n + 2) * sizeof(int));
	p = (int*)malloc((n + 2) * sizeof(int));
	visit = (int*)malloc((n + 2) * sizeof(int));
	topo = (int*)malloc((n + 2) * sizeof(int));

	INITIALIZE_SINGLE_SOURCE(d, p, visit, n, s);

	for (int u = 0; u <= n + 1; u++)
		if (visit[u] == WHITE)
			DFS_VISIT(G, u, visit, p, topo_sort);

	// TOPO_SORT 순서 맞추기.
	BLOCK* temp = topo_sort->tail;
	int i = n + 1;
	while (temp != NULL)
	{
		topo[i] = temp->_n;
		temp = temp->next;
		i--;
	}

	// TOPO_SORT 순서대로 RELAX
	for (int i = 0; i <= n + 1; i++)
		RELAX(G[topo[i]], d, p, topo[i]);

	printf("%d\n", TOWER_NUM(p, n + 1));
	PRINT_TOWER(p, n + 1);
	printf("height : %d\n", d[n + 1]);

	// d[n + 1] == 0 인 경우 / 149

	free(d);
	free(p);
	free(visit);
	free(topo);
}

int main()
{
	FILE* F;
	NODE** GRAPH;
	NODE* TOPO_SORT;
	BLOCK* block;
	int N = 0;

	if (!(F = fopen("input.txt", "r")))
	{
		printf("No FILE!\n");
		exit(0);
	}

	fscanf(F, "%d", &N);

	GRAPH = (NODE**)malloc((N + 2) * sizeof(NODE*));
	for (int i = 0; i <= N + 1; i++)
	{
		GRAPH[i] = (NODE*)malloc(sizeof(NODE));
		GRAPH[i]->head = NULL;
		GRAPH[i]->tail = NULL;
	}

	TOPO_SORT = (NODE*)malloc(sizeof(NODE));
	TOPO_SORT->head = NULL;
	TOPO_SORT->tail = NULL;

	block = (BLOCK*)malloc((N + 1) * sizeof(BLOCK));

	for (int i = 1; i <= N; i++)
		fscanf(F, "%d %d %d", &block[i]._s, &block[i]._h, &block[i]._w);

	MAKE_LIST(GRAPH, block, N);

	DFS(GRAPH, N, 0, TOPO_SORT);

	for (int i = 0; i <= N + 1; i++)
		FREE_NODE(GRAPH[i]);
	free(GRAPH);

	FREE_NODE(TOPO_SORT);

	free(block);

	fclose(F);

	return 0;
}