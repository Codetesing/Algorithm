#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DELETE -9999
#define END 9999

typedef struct {
	int key;
}element;

typedef struct {
	element *heap;
	int heap_size;
}HeapType;

int MAX_ELEMENT = 200;

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

void insert_max_heap(HeapType* h, element item)
{
	int i;

	if (IS_FULL(h))
		EXTEND_HEAP(h); // heap FULL 일때 2배로 크기 늘림.

	for (i = ++(h->heap_size); (i != 1) && (item.key > h->heap[i / 2].key); i /= 2)
		h->heap[i] = h->heap[i / 2];
	 
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;

	return item;
}

void print_max_heap(HeapType* h, int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d ", h->heap[i].key);
	printf("\n\n");
}

void heap_sort(HeapType* h)
{
	HeapType* sort_h;
	int n = h->heap_size;

	sort_h = create();
	init(sort_h);

	for (int i = 1; i <= n; i++)
		insert_max_heap(sort_h, h->heap[i]);

	for (int i = n; i > 0; i--)
		sort_h->heap[i] = delete_max_heap(sort_h);

	print_max_heap(sort_h, n);

	free(sort_h->heap);
	free(sort_h);
}

int main()
{
	FILE* F;
	HeapType* heap;
	element temp;
	int n;
	int input;

	if (!(F = fopen("heap_input1.txt", "r")))
	{
		printf("NO FILE.\n");
		exit(1);
	}

	fscanf(F, "%d", &n);

	heap = create();
	init(heap);

	for (int i = 0; i < n; i++)
	{
		fscanf(F, "%d", &temp.key);
		insert_max_heap(heap, temp);
	}

	print_max_heap(heap, heap->heap_size);
	heap_sort(heap);

	while (1)
	{
		scanf("%d", &input);

		if (input == END)
			break;

		else if (input == DELETE)
			delete_max_heap(heap);

		else
		{
			temp.key = input;
			insert_max_heap(heap, temp);
		}

		print_max_heap(heap, heap->heap_size);
	}

	free(heap->heap);
	free(heap);

	fclose(F);

	return 0;
}