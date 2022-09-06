#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sum[i][j] = sum[i][j - 1] + map[i][j];

	for (int i = 0; i < M; i++)
	{
		int x1, x2, y1, y2;
		int total = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++)
			total += sum[j][y2] - sum[j][y1 - 1];

		cout << total << '\n';
	}

	return 0;
}