#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
bool visited[10001][501] = { false };
vector<string> map;
int ROTATE_X[] = { -1, 0, 1 };

bool DFS(int r, int c) {
	if (c == C - 1)
		return true;

	visited[r][c] = true;
	for (int i = 0; i < 3; i++) {
		int next_r = r + ROTATE_X[i];
		int next_c = c + 1;

		if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C)
			continue;

		if (visited[next_r][next_c] || map[next_r][next_c] == 'x')
			continue;

		if(DFS(next_r, next_c))
			return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	string t;
	for (int i = 0; i < R; i++) {
		cin >> t;
		map.push_back(t);
	}

	int res = 0;
	for (int i = 0; i < R; i++)
		res += DFS(i, 0);

	cout << res << '\n';

	return 0;
}
