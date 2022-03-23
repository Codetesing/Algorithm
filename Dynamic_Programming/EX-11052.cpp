#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> P(N + 1);
	vector<int> DP(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> P[i];

	DP[1] = P[1];
	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= i; j++)
			if (DP[i - j] + P[j] > DP[i])
				DP[i] = DP[i - j] + P[j];

	cout << DP[N] << endl;

	return 0;
}