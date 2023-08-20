#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	set<int> A;
	int N, M; cin >> N >> M;
	
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		A.insert(t);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> t;
		if (A.find(t) != A.end())
			cnt++;
	}

	int ans = N + M - 2 * cnt;
	cout << ans << '\n';

	return 0;
}
