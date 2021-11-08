#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 21

struct pos {
	int x;
	int y;
	int dist;

	bool operator < (const pos p) const
	{
		if (dist == p.dist)
		{
			if (x == p.x)
				return y > p.y;

			else
				return x > p.x;
		}

		else
			return dist > p.dist;
	}
};

int space[MAX][MAX];
bool visit[MAX][MAX] = { false };

int rotate_x[4] = { -1, 0, 0, 1 };
int rotate_y[4] = { 0, -1, 1, 0 };

int result = 0;
int eaten = 0;
int Size = 2;

void BFS(pos shark, int n)
{
	priority_queue<pos> pq;

	pq.push({ shark.x, shark.y, shark.dist });

	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int dist = pq.top().dist;

		pq.pop();

		if (space[x][y] > 0 && space[x][y] < Size) {
			eaten++;
			space[x][y] = 0;

			if (Size == eaten) {
				Size++;
				eaten = 0;
			}
			result += dist;
			dist = 0;
			memset(visit, false, sizeof(visit));

			while (!pq.empty())
				pq.pop();
		}

		for (int i = 0; i < 4; i++) {

			int posX = x + rotate_x[i];
			int posY = y + rotate_y[i];

			if (posX < 0 || posX >= n || posY < 0 || posY >= n)
				continue;
			if (visit[posX][posY])
				continue;
			if (space[posX][posY] > Size)
				continue;

			pq.push({ posX, posY, dist + 1 });
			visit[posX][posY] = true;
		}
	}
}

int main()
{
	int N;
	pos shark;

	result = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{

			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				shark.dist = 0;
				Size = 2;
				eaten = 0;
				space[i][j] = 0;
			}
		}

	BFS(shark, N);
	
	cout << result << endl;

	return 0;
}