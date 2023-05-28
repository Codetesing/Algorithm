#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int C; cin >> C;
		int MOD[] = { 25, 10, 5, 1 };
		int cnt[4] = { 0 };

		for (int i = 0; i < 4; i++) {
			cnt[i] = C / MOD[i];
			C %= MOD[i];
		}

		for (int i = 0; i < 4; i++)
			cout << cnt[i] << ' ';
		cout << '\n';
	}

	return 0;
}
