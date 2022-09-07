#include <iostream>
#include <vector>

using namespace std;

#define MOD 9901

int main() {

	int N;
	cin >> N;

	vector<vector<int>> DP(N, vector<int>(3, 1));

	for (int i = 1; i < N; i++)
	{
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % MOD;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % MOD;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
	}

	cout << (DP[N - 1][0] + DP[N - 1][1] + DP[N - 1][2]) % MOD << '\n';

	return 0;
}