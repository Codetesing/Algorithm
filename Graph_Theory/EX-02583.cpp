#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100

int M, N, K, ind = -1;
int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, 1, -1, 0 };

bool visited[MAX][MAX] = { false };

vector<int> area;

void DFS(int x, int y)
{
	visited[x][y] = true;

	area[ind]++;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
			continue;

		if (!visited[next_x][next_y])
			DFS(next_x, next_y);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;

	int x1, x2, y1, y2;

	for (int i = 0; i < K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				visited[y][x] = true;
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j])
			{
				area.push_back(0);
				ind++;
				DFS(i, j);
			}

	sort(area.begin(), area.end());

	cout << ind + 1 << '\n';
	for (int i = 0; i < area.size(); i++)
		cout << area[i] << ' ';
	cout << '\n';

	return 0;
}