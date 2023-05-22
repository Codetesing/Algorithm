#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int DP[1001][1001] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int max_size = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != '0') {
				DP[i + 1][j + 1] = min({ DP[i][j], DP[i + 1][j], DP[i][j + 1] }) + 1;
				max_size = max(max_size, DP[i + 1][j + 1]);
			}
		}
	}

	cout << max_size * max_size << '\n';

	return 0;
}
