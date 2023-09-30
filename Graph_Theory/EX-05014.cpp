#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define MAX 1000001

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	int visited[MAX] = { 0 };
	queue<int> q;

	q.push(S);
	visited[S] = 1;

	int ans = -1;
	while (!q.empty()) {
		int cur = q.front();
		int cnt = visited[cur];
		q.pop();

		if (cur == G) {
			ans = cnt - 1;
			break;
		}
		
		int next_u = cur + U;
		int next_d = cur - D;

		if (next_u <= F && visited[next_u] == 0) {
			q.push(next_u);
			visited[next_u] = cnt + 1;
		}
		if (next_d > 0 && visited[next_d] == 0) {
			q.push(next_d);
			visited[next_d] = cnt + 1;
		}
	}

	if (ans == -1)
		cout << "use the stairs" << '\n';
	else
		cout << ans << '\n';

	return 0;
}
