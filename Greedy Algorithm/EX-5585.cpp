#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	N = 1000 - N;
	int excharge[] = { 500, 100, 50, 10, 5, 1 };

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		cnt += N / excharge[i];
		N %= excharge[i];
	}

	cout << cnt << '\n';
	
	return 0;
}
