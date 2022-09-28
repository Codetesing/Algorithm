#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, -1, 1, 0 };
int max_val = 0;

string map[20];

bool visited_alpha[26] = { false };

void DFS(int x, int y, int cnt) {

	max_val = max(max_val, cnt);

	visited_alpha[map[x][y] - 'A'] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C)
			continue;

		if(!visited_alpha[map[next_x][next_y] - 'A'])
			DFS(next_x, next_y, cnt + 1);
	}

	visited_alpha[map[x][y] - 'A'] = false;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> map[i];

	DFS(0, 0, 1);

	cout << max_val << '\n';

	return 0;
}