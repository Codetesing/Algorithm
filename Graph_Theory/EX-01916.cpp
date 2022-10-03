#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001
#define INF 200000000

typedef struct NODE {
	int e;
	int w;
}NODE;

struct compare {
	bool operator()(NODE& a, NODE& b) {
		return a.w > b.w;
	}
};

vector<NODE> graph[MAX];

bool visited[MAX] = { false };

int d[MAX];

void DIJKSTRA(int n) {

	priority_queue<NODE, vector<NODE>, compare> pq;
	d[n] = 0;
	pq.push({ n, d[n] });

	NODE temp;

	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();

		if (temp.w > d[temp.e])
			continue;

		for(int i = 0; i < graph[temp.e].size(); i++)
			if (d[temp.e] + graph[temp.e][i].w < d[graph[temp.e][i].e])
			{
				d[graph[temp.e][i].e] = d[temp.e] + graph[temp.e][i].w;
				pq.push({ graph[temp.e][i].e , d[graph[temp.e][i].e] });
			}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++)
		d[i] = INF;

	int v, e, w;
	for (int i = 0; i < M; i++)
	{
		cin >> v >> e >> w;
		graph[v].push_back({ e, w });
	}

	int start, end;
	cin >> start >> end;

	DIJKSTRA(start);

	cout << d[end] << '\n';
	
	return 0;
}