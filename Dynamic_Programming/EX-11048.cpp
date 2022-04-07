#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;

	vector<vector<int>> maze(N + 1, vector<int>(M + 1));
	vector<vector<int>> DP(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> maze[i][j];
			DP[i][j] = 0;
		}


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			DP[i][j] = maze[i][j] + max(max(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]);

	cout << DP[N][M] << '\n';

	return 0;
}