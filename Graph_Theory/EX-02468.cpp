#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100

int N;
int map[MAX][MAX];

int min_map = 101;
int max_map = 0;

int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, 1, -1, 0 };

bool visited[MAX][MAX][MAX] = {false};

void DFS(int i, int x, int y) {

	visited[i][x][y] = true;

	for (int j = 0; j < 4; j++)
	{
		int next_x = x + ROTATE_X[j];
		int next_y = y + ROTATE_Y[j];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
			continue;

		if (!visited[i][next_x][next_y])
			DFS(i, next_x, next_y);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			min_map = min(min_map, map[i][j]);
			max_map = max(max_map, map[i][j]);
		}
	}

	int max_area = 1;

	for (int i = min_map; i < max_map; i++)
	{
		int cnt = 0;

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (map[j][k] <= i)
					visited[i][j][k] = true;

		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
				if (!visited[i][j][k])
				{
					cnt++;
					DFS(i, j, k);
				}

		max_area = max(cnt, max_area);
	}

	cout << max_area << '\n';

	return 0;
}