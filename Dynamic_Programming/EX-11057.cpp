#define MOD 10007

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N; cin >> N;
	vector<vector<int>> DP(N + 1, vector<int>(10));

	for (int i = 0; i < 10; i++)
		DP[1][i] = 10 - i;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j < 10; j++)
		{
			int sum = 0;
			for (int k = j; k < 10; k++)
				sum += DP[i - 1][k];
			DP[i][j] = sum % MOD;
		}

	cout << DP[N][0] << endl;

	return 0;
}