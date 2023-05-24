#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int btn[] = { 300, 60, 10 };
	int cnt[3] = { 0 };

	int T; cin >> T;

	for (int i = 0; i < 3; i++) {
		cnt[i] = T / btn[i];
		T %= btn[i];
	}

	if (T != 0)
		cout << -1;
	else
		for (int i = 0; i < 3; i++)
			cout << cnt[i] << ' ';
	cout << '\n';

	return 0;
}
