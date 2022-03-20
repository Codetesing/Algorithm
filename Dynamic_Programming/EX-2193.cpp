#include <iostream>

using namespace std;

int main()
{
	int n;
	int res = 0;

	cin >> n;
	
	long long* DP = new long long[n + 1];
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	cout << DP[n] << endl;

	return (0);
}