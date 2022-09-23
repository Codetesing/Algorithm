#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int index) {

	visited[index] = true;

	for (int i = 0; i < graph[index].size(); i++)
		if (!visited[graph[index][i]])
			DFS(graph[index][i]);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		graph.push_back(vector<int>());
		visited.push_back(false);
	}

	for (int i = 0; i < M; i++)
	{
		int u, v; cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;
	for(int i = 1; i <= N; i++)
		if (!visited[i])
		{
			cnt++;
			DFS(i);
		}

	cout << cnt << '\n';

	return 0;
}