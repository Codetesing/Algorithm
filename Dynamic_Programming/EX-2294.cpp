#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	vector<int> DP(k + 1, 10001);
	vector<int> COIN(n);

	for (int i = 0; i < n; i++)
		cin >> COIN[i];
	

	sort(COIN.begin(), COIN.end());

	DP[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = COIN[i]; j <= k; j++)
			DP[j] = min(DP[j], DP[j - COIN[i]] + 1);

	if (DP[k] == 10001)
		DP[k] = -1;

	printf("%d\n", DP[k]);

	return 0;
}