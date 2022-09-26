#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321

typedef struct node {
	int w;
	int e;
} node;

struct compare {
	bool operator()(node& a, node& b) {
		return a.w > b.w;
	}
};

vector<int> d(20001, INF);
vector<vector<node>> g(20001);

void dijkstra(int n)
{
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ d[n], n });

	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();

		if (cur.w > d[cur.e])
			continue;

		for(node &next : g[cur.e])
			if (d[cur.e] + next.w < d[next.e]) {
				d[next.e] = d[cur.e] + next.w;
				pq.push({ d[next.e], next.e });
			}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int V, E; cin >> V >> E;

	int start; cin >> start;
	d[start] = 0;

	for (int i = 0; i < E; i++)
	{
		int n, w, e;
		cin >> n >> e >> w;

		g[n].push_back({ w, e });
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}

	return 0;
}