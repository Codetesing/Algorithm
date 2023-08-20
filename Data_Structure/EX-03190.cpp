#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

int rotate_x[] = { -1, 0, 1, 0 };
int rotate_y[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int board[101][101] = { 0 };
	int N; cin >> N;
	int K; cin >> K;
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		board[x][y] = 1;
	}
	int L, X; cin >> L;
	char C;
	map<int, char> m;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		m[X] = C;
	}

	deque<pair<int, int>> dq;
	int ans = 0;
	int dir = 1;
	bool flag = false;
	dq.push_back({ 1, 1 });
	while (1) {
		ans++;
		x = dq.front().first;
		y = dq.front().second;
		int next_x = x + rotate_x[dir];
		int next_y = y + rotate_y[dir];

		for (auto& i : dq) {
			if (i.first == next_x && i.second == next_y) {
				flag = true;
				break;
			}
		}
		if (next_x < 1 || next_x > N || next_y < 1 || next_y > N || flag)
			break;

		dq.push_front({ next_x, next_y });
		if (board[next_x][next_y] == 0)
			dq.pop_back();
		else
			board[next_x][next_y] = 0;
		if (m[ans] == 'D')
			dir = (dir + 1) % 4;
		else if (m[ans] == 'L')
			dir = (dir + 3) % 4;
	}

	cout << ans << '\n';

	return 0;
}
