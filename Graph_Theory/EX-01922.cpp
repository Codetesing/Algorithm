#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

typedef struct NODE {
	int e;
	int w;
}NODE;

struct compare {
	bool operator() (NODE& a, NODE& b) {
		return a.w > b.w;
	}
};

bool visited[MAX] = { false };
vector<NODE> graph[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	priority_queue<NODE, vector<NODE>, compare> pq;
	pq.push({ 1, 0 });

	NODE temp;
	int sum_weight = 0;

	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();

		if (visited[temp.e])
			continue;

		sum_weight += temp.w;
		visited[temp.e] = true;

		for (int i = 0; i < graph[temp.e].size(); i++)
			pq.push(graph[temp.e][i]);
	}

	cout << sum_weight << '\n';

	return 0;
}