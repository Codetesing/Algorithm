#define MOD 10007

#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;

	int DP[1001] = { 0 };
	DP[1] = 1;
	DP[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		DP[i] = 2 * DP[i - 2] + DP[i - 1];
		if (DP[i] > MOD)
			DP[i] %= MOD;
	}
	cout << DP[n] << endl;

	return 0;
}