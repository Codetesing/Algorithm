#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	stack<pair<int, int>> st;
	int N; cin >> N;

	int t;
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		while (!st.empty()) {
			if (st.top().second > t) {
				ans.push_back(st.top().first);
				break;
			}
			st.pop();
		}
		if (st.empty())
			ans.push_back(0);
		st.push({ i, t });
	}

	for (int i = 0; i < N - 1; i++)
		cout << ans[i] << ' ';
	cout << ans[N - 1] << '\n';

	return 0;
}
