#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int>&b) {
		return a.second < b.second;
	}
} cmp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;
	vector<pair<int, int>> jewel(N);
	vector<int> bag(K);
	
	for (int i = 0; i < N; i++)
		cin >> jewel[i].first >> jewel[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	long long price = 0;
	for (int i = 0, j = 0; i < K; i++) {
		while (j < N) {
			if (bag[i] >= jewel[j].first) {
				pq.push(jewel[j]);
				j++;
			}
			else {
				break;
			}
		}

		if (!pq.empty()) {
			price += pq.top().second;
			pq.pop();
		}
	}

	cout << price << '\n';

	return 0;
}
