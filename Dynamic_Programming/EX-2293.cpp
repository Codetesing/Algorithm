#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	
	vector<int> coin(n);
	vector<int> DP(k + 1, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	
	sort(coin.begin(), coin.end());
	DP[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			DP[j] += DP[j - coin[i]];

	cout << DP[k] << '\n';
}