#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10001

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
vector<NODE> arr[MAX];

int main() {

	int V, E;
	priority_queue<NODE, vector<NODE>, compare> pq;
	NODE temp;
	int sum_weight = 0;

	cin >> V >> E;

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}

	pq.push({ 1, 0 });

	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();

		if (!visited[temp.e])
		{
			sum_weight += temp.w;
			visited[temp.e] = true;

			for (int i = 0; i < arr[temp.e].size(); i++)
			{
				pq.push(arr[temp.e][i]);
			}
		}
	}

	cout << sum_weight << '\n';

	return 0;
}