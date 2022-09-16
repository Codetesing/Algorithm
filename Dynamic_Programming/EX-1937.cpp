#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[500][500] = { 0 };
int DP[500][500] = { 0 };
int N;
int max_value = 0;

int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, 1, -1, 0 };

 int DFS(int x, int y)
{
	 if (DP[x][y] != 0)
		 return DP[x][y];

	DP[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
			continue;

		if (map[x][y] >= map[next_x][next_y])
			continue;

		DP[x][y] = max(DP[x][y], DFS(next_x, next_y) + 1);
	}

	return DP[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			max_value = max(max_value, DFS(i, j));


	cout << max_value << '\n';

	return 0;
}