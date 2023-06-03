#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int res = 0;
	for (int i = N - 1; i > 0; i--) {
		if (v[i - 1] >= v[i]) {
			res += v[i - 1] - v[i] + 1;
			v[i - 1] = v[i] - 1;
		}
	}

	cout << res << '\n';

	return 0;
}
