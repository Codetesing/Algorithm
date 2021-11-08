#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 21

typedef struct NODE {
	int _x;
	int _y;
	int _dist;
	struct NODE* next;
}NODE;

typedef struct QUEUE {
	NODE* front;
	NODE* rear;
	int count;
}QUEUE;

int SPACE[MAX][MAX];
bool VISIT[MAX][MAX] = { false };

int ROTATE_x[4] = { -1, 0, 0, 1 };
int ROTATE_y[4] = { 0, -1, 1, 0 };

int RESULT = 0;
int EATEN = 0;
int SIZE = 2;

bool QUEUE_EMPTY(QUEUE* q)
{
	if (q->count == 0)
		return true;

	return false;
}

void ENQUEUE(QUEUE* q, int x, int y, int dist)
{
	NODE* cur = (NODE*)malloc(sizeof(NODE));
	cur->_x = x;
	cur->_y = y;
	cur->_dist = dist;
	cur->next = NULL;

	if (QUEUE_EMPTY(q))
		q->front = cur;
	else
		q->rear->next = cur;

	q->rear = cur;
	q->count++;
}

void DEQUEUE(QUEUE* q)
{
	NODE* cur;

	cur = q->front;
	q->front = cur->next;
	free(cur);
	q->count--;
}

void BFS(NODE shark, int n)
{
	QUEUE queue;

	int temp_x, temp_y, temp_dist;

	queue.front = NULL;
	queue.rear = NULL;
	queue.count = 0;

	ENQUEUE(&queue, shark._x, shark._y, shark._dist);

	while (!QUEUE_EMPTY(&queue))
	{
		int x = queue.front->_x;
		int y = queue.front->_y;
		int dist = queue.front->_dist;

		DEQUEUE(&queue);

		NODE* temp = queue.front;

		if (SPACE[x][y] > 0 && SPACE[x][y] < SIZE)
		{
			while (!QUEUE_EMPTY(&queue))
			{
				temp_x = queue.front->_x;
				temp_y = queue.front->_y;
				temp_dist = queue.front->_dist;

				if (SPACE[temp_x][temp_y] > 0 && SPACE[temp_x][temp_y] < SIZE)
				{
					if (dist == temp_dist)
					{
						if (x > temp_x)
						{
							x = temp_x;
							y = temp_y;
						}
						else if (x == temp_x)
							if (y > temp_y)
								y = temp_y;
					}
				}
				DEQUEUE(&queue);
			}

			EATEN++;
			SPACE[x][y] = 0;

			if (SIZE == EATEN)
			{
				SIZE++;
				EATEN = 0;
			}

			RESULT += dist;
			dist = 0;

			for (int i = 0; i < MAX; i++)
				for (int j = 0; j < MAX; j++)
					VISIT[i][j] = false;
		}

		for (int i = 0; i < 4; i++)
		{
			int pos_X = x + ROTATE_x[i];
			int pos_Y = y + ROTATE_y[i];

			if (pos_X < 0 || pos_X >= n || pos_Y < 0 || pos_Y >= n)
				continue;
			if (VISIT[pos_X][pos_Y])
				continue;
			if (SPACE[pos_X][pos_Y] > SIZE)
				continue;

			ENQUEUE(&queue, pos_X, pos_Y, dist + 1);
			VISIT[pos_X][pos_Y] = true;
		}
	}
}

int main()
{
	int N;
	NODE shark;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &SPACE[i][j]);
			if (SPACE[i][j] == 9)
			{
				shark._x = i;
				shark._y = j;
				shark._dist = 0;
				SPACE[i][j] = 0;
			}
		}

	BFS(shark, N);

	printf("%d\n", RESULT);

	return 0;
}