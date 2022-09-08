#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<vector<long long>> DP(N, vector<long long>(N, 0));
	vector<vector<int>> map(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	DP[0][0] = 1;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == N - 1 && j == N - 1)
				break;

			if (DP[i][j] == 0)
				continue;
			else
			{
				if (i + map[i][j] < N)
					DP[i + map[i][j]][j] += DP[i][j];
				if (j + map[i][j] < N)
					DP[i][j + map[i][j]] += DP[i][j];
			}
		}

	cout << DP[N - 1][N - 1] << '\n';

	return 0;
}