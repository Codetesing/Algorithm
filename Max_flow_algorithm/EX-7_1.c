#define _CRT_SECURE_NO_WARNINGS

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
	printf("%d %d %d", n, m, w);
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

void FREE_NODE(LIST g)
{
	NODE* temp = g.next;

	while (temp != NULL)
	{
		temp = g.next->next;
		free(g.next);
	}
	free(temp);
}

int main()
{
	FILE* f = NULL;
	LIST* GRAPH = NULL;
	int v_num, e_num;
	int S, T;
	int n, m, w;
	bool** VISIT = NULL;

	if (!(f = fopen("input1.txt", "r")))
	{
		printf("NO FILE.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &v_num, &e_num);

	S = 0;
	T = v_num + 1;

	GRAPH = (LIST*)malloc(T * sizeof(LIST));
	for (int i = 0; i < T; i++)
		GRAPH[i].next = NULL;
	
	VISIT = (bool**)malloc(T * sizeof(bool*));
	for (int i = 0; i < T; i++)
		VISIT[i] = (bool*)malloc(T * sizeof(bool));

	memset(VISIT, false, T * T * sizeof(bool));

	for (int i = 0; i < T; i++)
		for (int j = 0; j < T; j++)
			printf("abc", VISIT[i][j]);

	for (int i = 0; i < e_num; i++)
	{
		fscanf(f, "%d %d %d", &n, &m, &w);
		if (!VISIT[n][m])
		{
			APPEND_NODE(GRAPH, n, m, w);
			VISIT[n][m] = true;
			VISIT[m][n] = true;
		}
		//else
			//CORRECT_NODE(GRAPH[n], m, w);
	}

	for (int i = 0; i < T; i++)
		FREE_NODE(GRAPH[i]);
	free(GRAPH);

	for (int i = 0; i < T; i++)
		free(VISIT[i]);
	free(VISIT);

	fclose(f);

	return 0;
}