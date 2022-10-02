#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 32001

vector<int> map[MAX];
bool visited[MAX];
vector<int> topo;

void DFS(int index) {
	
	visited[index] = true;

	for (int i = 0; i < map[index].size(); i++)
		if (!visited[map[index][i]])
		{
			DFS(map[index][i]);
		}
	topo.push_back(index);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;

	int start, end;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		map[start].push_back(end);
	}

	for (int i = 1; i <= N; i++)
		if(!visited[i])
			DFS(i);

	reverse(topo.begin(), topo.end());

	for (int i = 0; i < topo.size(); i++)
		cout << topo[i] << ' ';
	cout << '\n';

	return 0;
}