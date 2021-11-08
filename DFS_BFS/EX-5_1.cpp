#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

#define MAX 1000

struct pos {
	int x;
	int y;
	int eaten;
	int size;
};

int rotate_x[4] = { -1, 0, 0, 1 };
int rotate_y[4] = { 0, -1, 1, 0 };
int** visit;
int temp_x, temp_y;
int Min;

void  INIT(int** visit, int n)
{
	Min = MAX;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = -1;
}

bool CHECK(int x, int y, int n)
{
	if (((x >= n) || (y >= n)) || ((x < 0) || (y < 0)))
		return false;

	return true;
}

void BFS(pos shark, int **space,  int **visit, int n)
{
	queue<pair<int, int>> pq;
	int x, y;
	int check_x, check_y;

	pq.push({ shark.x, shark.y});
	visit[shark.x][shark.y] = 0;

	while (!pq.empty())
	{
		x = pq.front().first;
		y = pq.front().second;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			check_x = x + rotate_x[i];
			check_y = y + rotate_y[i];

			if (!CHECK(check_x, check_y, n))
				continue;

			if ((visit[check_x][check_y] != -1) || (space[check_x][check_y] > shark.size))
				continue;

			visit[check_x][check_y] = visit[x][y] + 1;

			if ((space[check_x][check_y] < shark.size) && (space[check_x][check_y] != 0))
			{
				if (Min > visit[check_x][check_y])
				{
					temp_x = check_x;
					temp_y = check_y;
					Min = visit[check_x][check_y];
				}
						
				else if (Min == visit[check_x][check_y])
				{
					if (temp_x == check_x) {
						if (temp_y > check_y) {
							temp_x = check_y;
							temp_y = check_y;
						}
					}
					else if (temp_x > check_x) {
						temp_x = check_x;
						temp_y = check_y;
					}
				};
			}
			pq.push({ check_x, check_y });
		}
	}
}

int main()
{
	int N;
	int** Space;
	int** Visit;
	pos shark;
	int tok, result;

	result = 0;
	cin >> N;

	Space = (int**)malloc(N * sizeof(int*));
	Visit = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		Space[i] = (int*)malloc(N * sizeof(int));
		Visit[i] = (int*)malloc(N * sizeof(int));
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{

			cin >> Space[i][j];
			if (Space[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.eaten = 0;
				Space[i][j] = 0;
			}
		}


	while (1)
	{
		INIT(Visit, N);
		BFS(shark, Space, Visit, N);

		if (Min == MAX)
			break;

		shark.x = temp_x;
		shark.y = temp_y;
		result += Visit[temp_x][temp_y];
		shark.eaten++;
		Space[shark.x][shark.y] = 0;

		if (shark.eaten == shark.size)
		{
			shark.size++;
			shark.eaten = 0;
		}
	}

	cout << result << endl;

	for (int i = 0; i < N; i++)
	{
		free(Space[i]);
		free(Visit[i]);
	}
	free(Space);
	free(Visit);

	return 0;
}