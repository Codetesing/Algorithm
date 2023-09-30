#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	priority_queue<int> pq;
	long long ans = 0;
	int ind = N - 1;

	for (int i = N; i > 0; i--) {
		while (ind >= 0 && v[ind].first == i) {
			pq.push(v[ind].second);
			ind--;
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << '\n';

	return 0;
}
