#include <iostream>
#include <vector>

using namespace std;

int ROTATE_X[] = { -1, 1, 0, 0 };
int ROTATE_Y[] = { 0, 0, -1, 1 };

int DP[501][501];
int map[501][501];
int N, M;

int DFS(int row, int col)
{
	if (row == N && col == M)
		return 1;
	if (DP[row][col] != -1)
		return DP[row][col];

	DP[row][col] = 0;

	int next_row, next_col;
	for (int i = 0; i < 4; i++)
	{
		next_row = row + ROTATE_X[i];
		next_col = col + ROTATE_Y[i];

		if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= M)
			if (map[next_row][next_col] < map[row][col])
				DP[row][col] += DFS(next_row, next_col);
	}

	return DP[row][col];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			DP[i][j] = -1;
		}

	cout << DFS(1, 1) << '\n';

	return 0;
}