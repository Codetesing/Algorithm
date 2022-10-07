#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50

int N, L, R;

int graph[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> index;
int sum;

int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, -1, 1, 0 };

void BFS(int x, int y) {

	queue<pair<int, int>> q;

	q.push({ x, y });
	sum = graph[x][y];
	visited[x][y] = true;

	while (!q.empty()) 
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur.first + ROTATE_X[i];
			int next_y = cur.second + ROTATE_Y[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;

			if (visited[next_x][next_y] || abs(graph[cur.first][cur.second] - graph[next_x][next_y]) < L || abs(graph[cur.first][cur.second] - graph[next_x][next_y]) > R)
				continue;

			sum += graph[next_x][next_y];
			q.push({ next_x, next_y });
			index.push_back({ next_x, next_y });
			visited[next_x][next_y] = true;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];

	int day = 0;
	bool flag = true;

	while (flag)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = false;

		flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					index.clear();
					index.push_back({ i, j });
					BFS(i, j);
				}

				if (index.size() >= 2)
				{
					flag = true;
					for (int k = 0; k < index.size(); k++)
						graph[index[k].first][index[k].second] = sum / index.size();
				}
			}
		}
		if (flag)
			day++;
	}

	cout << day << '\n';

	return 0;
}