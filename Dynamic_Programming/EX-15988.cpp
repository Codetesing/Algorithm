#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 1000001
#define MOD 1000000009

using namespace std;

long long DP[MAX] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	int max_ind = 3;
	for (int i = 0; i < T; i++) {
		int n; cin >> n;

		if(max_ind < n) {
			for (int j = max_ind + 1; j <= n; j++) 
				DP[j] = (DP[j - 1] + DP[j - 2] + DP[j - 3]) % MOD;
			max_ind = n;
		}

		cout << DP[n] << '\n';
	}
	
	return 0;
}
