#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> DP(N + 1, 0);

	for (int i = 1; i <= N; i++)
		DP[i] = i;

	for (int i = 4; i <= N; i++)
		for (int j = 2; j * j <= i; j++)
			DP[i] = min(DP[i], DP[i - j * j] + 1);

	cout << DP[N] << '\n';

	return 0;
}