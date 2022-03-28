#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[1001];

int main()
{
	int N; cin >> N;

	vector<int> A(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 1; i <= N; i++)
		DP[i] = A[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			if (A[i] > A[j])
				DP[i] = max(DP[i], DP[j] + A[i]);
	}

	int out = *max_element(DP, DP + 1001);

	cout << out << endl;

	return 0;
}