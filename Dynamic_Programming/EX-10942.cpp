#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;

	vector<vector<int>> DP(N + 1, vector<int>(N + 1, 0));
	vector<int> map(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> map[i];
		DP[i][i] = 1;
	}

	for(int i = 1; i < N; i++)
		for (int j = 1; j <= N - i; j++)
		{
			if (map[j] == map[i + j])
				if (i == 1 || DP[j + 1][i + j - 1] == 1)
					DP[j][i + j] = 1;
		}

	int M; cin >> M;

	for (int i = 0; i < M; i++)
	{
		int S, E; cin >> S >> E;
		cout << DP[S][E] << '\n';
	}

	return 0;
}