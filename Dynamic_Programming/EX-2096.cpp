#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	//vector<vector<int>> map(N, vector<int>(3, 0));
	
	int map[100001][3];
	vector<int> max_dp(3, 0);
	vector<int> min_dp(3, 0);
	vector<int> prev_max_dp(3, 0);
	vector<int> prev_min_dp(3, 0);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];

	for (int i = 0; i < 3; i++)
	{
		max_dp[i] = map[0][i];
		min_dp[i] = map[0][i];
		prev_max_dp[i] = map[0][i];
		prev_min_dp[i] = map[0][i];
	}

	for (int i = 1; i < N; i++)
	{
		max_dp[0] = max(prev_max_dp[0], prev_max_dp[1]) + map[i][0];
		max_dp[1] = max(max(prev_max_dp[0], prev_max_dp[1]), prev_max_dp[2]) + map[i][1];
		max_dp[2] = max(prev_max_dp[1], prev_max_dp[2]) + map[i][2];

		min_dp[0] = min(prev_min_dp[0], prev_min_dp[1]) + map[i][0];
		min_dp[1] = min(min(prev_min_dp[0], prev_min_dp[1]), prev_min_dp[2]) + map[i][1];
		min_dp[2] = min(prev_min_dp[1], prev_min_dp[2]) + map[i][2];

		for (int j = 0; j < 3; j++)
		{
			prev_max_dp[j] = max_dp[j];
			prev_min_dp[j] = min_dp[j];
		}
	}

	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << ' ';
	cout << min(min(min_dp[0], min_dp[1]), min_dp[2]) << '\n';

	return 0;
}