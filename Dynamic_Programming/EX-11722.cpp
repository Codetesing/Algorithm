#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	vector<int> DP(N + 1, 0);
	int out = 0;
	for (int i = 1; i <= N; i++)
	{
		DP[i] = 1;
		for (int j = 1; j <= i; j++)
			if (A[i] < A[j] && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		if (out < DP[i])
			out = DP[i];
	}

	cout << out << '\n';

	return 0;
}