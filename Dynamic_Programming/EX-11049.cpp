#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	int min_value = 0;

	vector<pair<int, int>> map;
	vector<vector<int>> DP(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; i++)
	{
		int r, c; cin >> r >> c;
		map.push_back(make_pair(r, c));
	}

	for (int i = 1; i < N; i++)
		for (int j = 0; j + i < N; j++)
		{
			DP[j][j + i] = INT_MAX;
			for (int k = 0; k <= i - 1; k++)
				DP[j][j + i] = min(DP[j][j + k] + DP[j + k + 1][j + i] + map[j].first * map[j + k].second * map[j + i].second, DP[j][j + i]);
		}
	cout << DP[0][N - 1] << '\n';

	return 0;
}