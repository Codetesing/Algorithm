#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> DP(N + 1, 0);

	DP[0] = 1;
	DP[2] = 3;
	for (int i = 4; i <= N; i += 2)
	{
		DP[i] = DP[i - 2] * 3;
		for (int j = 4; j <= i; j += 2)
			DP[i] += 2 * DP[i - j];
	}


	cout << DP[N] << '\n';

	return 0;
}