#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[8][8];
int temp[8][8];
int max_val = 0;
int visited[8][8];

int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, 1, -1, 0 };

void DFS(int x, int y) {

	visited[x][y] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			continue;

		if (temp[next_x][next_y] == 0)
		{
			temp[next_x][next_y] = 2;
			DFS(next_x, next_y);
		}
	}
}

void solution() {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			temp[i][j] = map[i][j];
			visited[i][j] = 0;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 2 && !visited[i][j])
				DFS(i, j);

	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 0)
				cnt++;

	max_val = max(max_val, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int x1 = 0; x1 < N; x1++)
		for (int y1 = 0; y1 < M; y1++)
			if (map[x1][y1] == 0)
				for (int x2 = 0; x2 < N; x2++)
					for (int y2 = 0; y2 < M; y2++)
					{
						if (x1 == x2 && y1 == y2)
							continue;

						if (map[x2][y2] == 0)
							for (int x3 = 0; x3 < N; x3++)
								for (int y3 = 0; y3 < M; y3++)
								{
									if (x1 == x3 && y1 == y3)
										continue;
									if (x2 == x3 && y2 == y3)
										continue;

									if (map[x3][y3] == 0)
									{
										map[x1][y1] = 1;
										map[x2][y2] = 1;
										map[x3][y3] = 1;

										solution();

										map[x1][y1] = 0;
										map[x2][y2] = 0;
										map[x3][y3] = 0;
									}
								}
					}
	cout << max_val << '\n';

	return 0;
}