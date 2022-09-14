#include <iostream>
#include <vector>

using namespace std;

#define MAX 20

int map[MAX][MAX] = { 0 };
int N;
int cnt = 0;

void DFS(int x, int y, int dir)
{
	if (x < 1 || x > N || y < 1 || y > N)
		return;

	if (map[x][y] == 1)
		return;

	if (x == N && y == N)
	{
		cnt++;
		return;
	}
	if (dir == 1)
		DFS(x, y + 1, 1);
	if (dir == 2)
		DFS(x + 1, y, 2);
	if (dir == 3)
	{
		DFS(x, y + 1, 1);
		DFS(x + 1, y, 2);
	}

	if (!map[x][y + 1] && !map[x + 1][y] && !map[x + 1][y + 1])
		DFS(x + 1, y + 1, 3);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	DFS(1, 2, 1);

	cout << cnt << '\n';

	return 0;
}