#include <iostream>
#include <vector>

using namespace std;

vector<int> map[101];
bool visited[101] = { false };
int output = -1;

void DFS(int start, int end, int cnt) {

	visited[start] = true;

	if (start == end)
	{
		output = cnt;
		return;
	}

	for (int i = 0; i < map[start].size(); i++)
		if (!visited[map[start][i]])
			DFS(map[start][i], end, cnt + 1);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int start, end; cin >> start >> end;
	int m; cin >> m;

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}

	DFS(start, end, 0);

	cout << output << '\n';

	return 0;
}