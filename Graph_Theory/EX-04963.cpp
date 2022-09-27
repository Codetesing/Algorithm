#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int map[50][50];
bool visited[50][50];
int w, h;

int ROTATE_X[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int ROTATE_Y[] = { -1, -1, -1, 0, 1, 1, 1, 0 };

void DFS(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 8; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w)
			continue;

		if(!visited[next_x][next_y] && map[next_x][next_y] == 1)
			DFS(next_x, next_y);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;
		
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		for(int i = 0; i < 50; i++)
			memset(visited[i], false, sizeof(visited[i]));

		int out = 0;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (!visited[i][j] && map[i][j] == 1)
				{
					out++;
					DFS(i, j);
				}

		cout << out << '\n';
	}

	return 0;
}