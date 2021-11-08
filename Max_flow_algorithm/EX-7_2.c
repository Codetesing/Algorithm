#define _CRT_SECURE_NO_WARNINGS

#define NIL -1
#define INFINITY 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct NODE{
	int v;
	int c;
	int f;
	struct NODE* p;
	struct NODE* next;
}NODE;

typedef struct LIST {
	NODE* last;
	NODE* next;
}LIST;

typedef struct QUEUE {
	NODE* front;
	NODE* rear;
	int num;
}QUEUE;

int TOTAL = 0;
int min;

void APPEND_NODE(LIST* G, int n, int m, int w)
{
	NODE* temp1 = (NODE*)malloc(sizeof(NODE));
	NODE* temp2 = (NODE*)malloc(sizeof(NODE));

	temp1->v = m;
	temp1->f = 0;
	temp1->c = w;
	temp1->p = temp2;
	temp1->next = NULL;

	temp2->v = n;
	temp2->f = 0;
	temp2->c = 0;
	temp2->p = temp1;
	temp2->next = NULL;

	if (G[n].next == NULL)
	{
		G[n].next = temp1;
		G[n].last = temp1;
	}

	else
	{
		G[n].last->next = temp1;
		G[n].last = temp1;
	}

	if (G[m].next == NULL)
	{
		G[m].next = temp2;
		G[m].last = temp2;
	}

	else
	{
		G[m].last->next = temp2;
		G[m].last = temp2;
	}
}

void CORRECT_NODE(LIST G, int m, int w)
{
	NODE* temp = G.next;

	while (temp->v != m)
		temp = temp->next;

	temp->c = w;
}

void PRINT_NODE(LIST* G, int T)
{
	NODE* temp;

	printf("총 노드 개수 : %d\n", TOTAL);

	for (int i = 0; i <= T; i++)
	{
		temp = G[i].next;

		printf("%d:", i);

		while (temp != NULL)
		{
			printf("->(%d %d %d %d)", temp->v, temp->c, temp->f, temp->p);
			temp = temp->next;
		}
		
		printf("\n");
	}
}

void FREE_NODE(LIST G)
{
	NODE* temp = G.next;

	while (temp != NULL)
	{
		temp = G.next->next;
		free(G.next);
		G.next = temp;
	}
	free(G.next);
}

bool QUEUE_EMPTY(QUEUE* q)
{
	if (q->num == 0)
		return true;

	return false;
}

void ENQUEUE(QUEUE* q, NODE* cur)
{

	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->v = cur->v;
	temp->next = NULL;

	if (QUEUE_EMPTY(q))
		q->front = temp;
	else
		q->rear->next = temp;

	q->rear = temp;
	q->num++;
}

void DEQUEUE(QUEUE* q)
{
	NODE* cur;

	cur = q->front;
	q->front = cur->next;
	q->num--;
}

void INITIALIZE_SINGLE_SOURCE(int* p, int* color, int s, int v, NODE** p_node)
{
	for (int i = 0; i <= v; i++)
	{
		p[i] = NIL;
		color[i] = WHITE;
		p_node[i] = NULL;
	}
}

void BFS(LIST* G, int*p, NODE** p_node, int s, int t)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	NODE* temp;
	int* color = NULL;
	int u = 0;

	color = (int*)malloc((t + 1) * sizeof(int));
	temp = (NODE*)malloc(sizeof(NODE));
	temp->v = 0;
	min = 100;

	queue->front = NULL;
	queue->rear = NULL;
	queue->num = 0;
	INITIALIZE_SINGLE_SOURCE(p, color, s, t, p_node);
	color[s] = GRAY;
	ENQUEUE(queue, temp);

	while (!QUEUE_EMPTY(queue))
	{
		u = queue->front->v;

		temp = G[u].next;

		while (temp != NULL)
		{
			if(0 < temp->c - temp->f)
			{
				if (color[temp->v] == WHITE)
				{
					p[temp->v] = u;
					if(p_node[temp->v] == NULL)
						p_node[temp->v] = temp;
					if (min > temp->c - temp->f)
						min = temp->c - temp->f;
					color[temp->v] = GRAY;
					ENQUEUE(queue, temp);
				}
			}
			temp = temp->next;
		}
		DEQUEUE(queue);
		color[u] = BLACK;
	}

	free(color);
	free(queue);
}

void MAX_FLOW(LIST* G, int s, int t)
{
	// S -> T로 가는 root가 없을때까지(parent[T] == -1) BFS -> parent를 구하여 (parent에 맞는 link 저장) 따라가면서 min을 뺸다.
	NODE** parent_node;
	int* parent;

	parent = (int*)malloc((t + 1) * sizeof(int));
	parent_node = (NODE**)malloc((t + 1) * sizeof(NODE*));

	while(parent[t] != -1)
	{
		BFS(G, parent, parent_node, 0, t);

		for (int i = t; parent[i] != -1; i = parent[i])
		{
			parent_node[i]->f += min;
			parent_node[i]->p->f = (-1 * min);
		}
	}

	free(parent);
	free(parent_node);
}

void PRINT_MAX_FLOW(LIST G)
{
	NODE* temp = G.next;
	int sum = 0;

	while (temp != NULL)
	{
		sum += temp->f;
		temp = temp->next;
	}

	printf("\n\nMax Flow is %d\n", sum);
}

int main()
{
	FILE* f = NULL;
	LIST* GRAPH = NULL;
	int v_num, e_num;
	int S, T;
	int n, m, w;
	bool** VISIT = NULL;

	if (!(f = fopen("input4.txt", "r")))
	{
		printf("NO FILE.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &v_num, &e_num);

	S = 0;
	T = v_num + 1;

	GRAPH = (LIST*)malloc((T + 1) * sizeof(LIST));
	for (int i = 0; i <= T; i++)
		GRAPH[i].next = NULL;

	VISIT = (bool**)malloc((T + 1) * sizeof(bool*));
	for (int i = 0; i <= T; i++)
		VISIT[i] = (bool*)malloc((T + 1) * sizeof(bool));

	for (int i = 0; i <= T; i++)
		for (int j = 0; j <= T; j++)
			VISIT[i][j] = false;

	for (int i = 0; i < e_num; i++)
	{
		fscanf(f, "%d %d %d", &n, &m, &w);
		if (!VISIT[n][m])
		{
			APPEND_NODE(GRAPH, n, m, w);
			TOTAL += 2;
			VISIT[n][m] = true;
			VISIT[m][n] = true;
		}
		else
			CORRECT_NODE(GRAPH[n], m, w);
	}

	PRINT_NODE(GRAPH, T);

	MAX_FLOW(GRAPH, S, T);

	PRINT_MAX_FLOW(GRAPH[0]);

	for (int i = 0; i <= T; i++)
		FREE_NODE(GRAPH[i]);
	free(GRAPH);
	
	for (int i = 0; i <= T; i++)
		free(VISIT[i]);
	free(VISIT);

	fclose(f);

	return 0;
}