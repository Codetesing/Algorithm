#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITE 9999
#define NIL -1

typedef struct NODE {
	int v;
	int w;
	struct NODE* next;
}NODE;

typedef struct LIST {
	struct NODE* last;
	struct NODE* next;
}LIST;

typedef struct {
	int v;
	int d;
}element;

typedef struct {
	element* heap;
	int heap_size;
}HeapType;

int TOTAL_NODE = 0;
int MAX_ELEMENT = 200;

void APPEND_NODE(LIST* G, int n, int m, int w)
{
	NODE* temp1 = (NODE*)malloc(sizeof(NODE));

	temp1->v = m;
	temp1->w = w;
	temp1->next = NULL;

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
	TOTAL_NODE += 1;
}

void PRINT_NODE(LIST* G, int v)
{
	NODE* temp;

	for (int i = 1; i <= v; i++)
	{
		temp = G[i].next;

		printf("%d:", i);

		for (temp = G[i].next; temp != NULL; temp = temp->next)
			printf(" (%d %d)", temp->v, temp->w);
		printf("\n");
	}
	printf("count : %d\n\n\n", TOTAL_NODE);
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

HeapType* create()
{
	HeapType* temp = (HeapType*)malloc(sizeof(HeapType));

	temp->heap = (element*)malloc(MAX_ELEMENT * sizeof(element));

	return temp;
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

bool IS_FULL(HeapType* h)
{
	if (h->heap_size == MAX_ELEMENT)
		return true;

	return false;
}

void EXTEND_HEAP(HeapType* h)
{
	MAX_ELEMENT *= 2;
	h->heap = (element*)realloc(h->heap, MAX_ELEMENT * sizeof(element));
}

void insert_min_heap(HeapType* h, element item)
{
	int i;

	if (IS_FULL(h))
		EXTEND_HEAP(h); // heap FULL 일때 2배로 크기 늘림.

	for (i = ++(h->heap_size); (i != 1) && (item.d < h->heap[i / 2].d); i /= 2)
		h->heap[i] = h->heap[i / 2];

	h->heap[i] = item;
}

element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].d > h->heap[child + 1].d))
			child++;
		if (temp.d < h->heap[child].d)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;

	return item;
}

void print_min_heap(HeapType* h, int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d ", h->heap[i].d);
	printf("\n\n");
}

void DIJKSTRA(LIST* G, int v_num)
{
	int* d;
	int* flag;
	int* parent;
	HeapType* heap;
	element temp;

	// d, flag, parent 초기화
	d = (int*)malloc((v_num + 1) * sizeof(int));
	flag = (int*)malloc((v_num + 1) * sizeof(int));
	parent = (int*)malloc((v_num + 1) * sizeof(int));

	for (int i = 1; i <= v_num; i++)
	{
		d[i] = INFINITE;
		flag[i] = 0;
		parent[i] = -1;
	}
	d[1] = 0;
	parent[0] = NIL;

	// heap 생성, temp = (v, d) = (1, 0) 으로 시작.
	heap = create();
	init(heap);

	temp.v = 1;
	temp.d = 0;

	insert_min_heap(heap, temp);

	// n번의 수행 (1~10까진데 n-1) -> n - 1로 줄이는법, print_heap 의 위치
	while (heap->heap_size != 0)
	{
		temp = delete_min_heap(heap);
		int u = temp.v;
		if (flag[u] == 0)
		{
			for (NODE* temp2 = G[u].next; temp2 != NULL; temp2 = temp2->next)
			{
				if ((flag[temp2->v] == 0) && (d[temp2->v] > d[u] + temp2->w))
				{
					parent[temp2->v] = u;
					d[temp2->v] = d[u] + temp2->w;

					temp.v = temp2->v;
					temp.d = d[temp2->v];
					insert_min_heap(heap, temp);
				}
			}
			print_min_heap(heap, heap->heap_size);
		}
		//print_min_heap(heap, heap->heap_size);
		flag[u] = 1;
	}
	// parent 출력
	printf("parent : ");
	for (int i = 1; i <= v_num; i++)
		printf("%d ", parent[i]);
	printf("\n");
	// weight 출력
	printf("weight : ");
	for (int i = 1; i <= v_num; i++)
		printf("%d ", d[i]);
	printf("\n");

	free(d);
	free(flag);
	free(parent);
	free(heap->heap);
	free(heap);
}

int main()
{
	FILE* F;
	LIST* adj_list;
	int v_num, e_num;
	int n, m, w;

	if (!(F = fopen("input1.txt", "r")))
	{
		printf("No file!\n");
		exit(1);
	}

	fscanf(F, "%d %d", &v_num, &e_num);

	// adj_list 생성
	adj_list = (LIST*)malloc((v_num + 1) * sizeof(LIST));
	for (int i = 0; i <= v_num; i++)
		adj_list[i].next = NULL;

	for (int i = 0; i < e_num; i++)
	{
		fscanf(F, "%d %d %d", &n, &m, &w);
		APPEND_NODE(adj_list, n, m, w);
	}

	// DIJKSTRA Algorithm
	DIJKSTRA(adj_list, v_num);

	for (int i = 0; i <= v_num; i++)
		FREE_NODE(adj_list[i]);
	free(adj_list);

	fclose(F);

	return 0;
}