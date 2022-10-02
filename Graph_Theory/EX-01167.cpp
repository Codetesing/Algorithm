#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100001

typedef struct NODE {
	int e;
	int w;
}NODE;

int max_len = 0, max_node = 0;
vector<NODE> graph[MAX];
bool visited[MAX] = { false };

void DFS(int index, int len) {
	visited[index] = true;

	for (int i = 0; i < graph[index].size(); i++)
		if (!visited[graph[index][i].e])
			DFS(graph[index][i].e, len + graph[index][i].w);
	
	if (max_len < len)
	{
		max_len = len;
		max_node = index;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int V; cin >> V;

	int in_V, in_E, in_W;
	for (int i = 0; i < V; i++)
	{
		cin >> in_V;
		while (1) {
			cin >> in_E;
			if (in_E == -1)
				break;

			cin >> in_W;

			graph[in_V].push_back({ in_E, in_W });
		}
	}

	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	DFS(max_node, 0);

	cout << max_len << '\n';

	return 0;
}