#include <iostream>
#include <vector>

using namespace std;

#define DIV 1000000000

int main() {

	int N, K;
	cin >> N >> K;

	vector<vector<int>> DP(K + 1, vector<int>(N + 1, 0));
	DP[0][0] = 1;

	for(int i = 1; i <= K; i++)
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++)
			{
				DP[i][j] += DP[i - 1][j - k];
				DP[i][j] %= DIV;
			}
		}

	cout << DP[K][N] << endl;

	return 0;
}