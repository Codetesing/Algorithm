#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<string> map;
vector<string> gr_map;

bool visited[100][100] = { false };
bool gr_visited[100][100] = { false };

int N;
int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, 1, -1, 0 };

void DFS(int x, int y) {

	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
			continue;

		if (!visited[next_x][next_y] && map[x][y] == map[next_x][next_y])
			DFS(next_x, next_y);
	}

}

void gr_DFS(int x, int y) {

	gr_visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
			continue;

		if (!gr_visited[next_x][next_y] && gr_map[x][y] == gr_map[next_x][next_y])
			gr_DFS(next_x, next_y);
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		map.push_back(temp);
		gr_map.push_back(temp);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (gr_map[i][j] == 'R')
				gr_map[i][j] = 'G';

	int map_num = 0, gr_num = 0;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				map_num++;
				DFS(i, j);
			}
		}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (!gr_visited[i][j])
			{
				gr_num++;
				gr_DFS(i, j);
			}
		}

	cout << map_num << ' ' << gr_num << '\n';

	return 0;
}