#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N = 0; cin >> N;
	int temp;
	vector<vector<int>> COST;
	for (int i = 0; i < N; i++) {
		COST.push_back(vector<int>());
		for (int j = 0; j < 3; j++) {
			cin >> temp;
			COST[i].push_back(temp);
		}
	}

	vector<vector<int>> DP(N, vector<int>(3, 0));

	for (int i = 0; i < 3; i++) {
		DP[0][i] = COST[0][i];
	}

	for (int i = 1; i < N; i++) {
		DP[i][0] = COST[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
		DP[i][1] = COST[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
		DP[i][2] = COST[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
	}

	int answer = *min_element(DP[N - 1].begin(), DP[N - 1].end());

	cout << answer << '\n';

	return 0;
}
