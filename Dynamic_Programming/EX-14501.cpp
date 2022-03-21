#include <iostream>
#include <vector>

using namespace std;

int DP[20] = { 0 };

int main()
{
	int N; cin >> N;
	int T, P;

	for (int i = 0; i < N; i++)
	{
		cin >> T >> P;

		if (DP[i] > DP[i + 1])
			DP[i + 1] = DP[i];

		if (DP[i + T] < DP[i] + P)
			DP[i + T] = DP[i] + P;
	}

	cout << DP[N] << endl;

	return 0;
}