#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int DP[1001][1001] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string A, B;
	string ans = "";

	cin >> A >> B;

	int len_a = A.length();
	int len_b = B.length();

	for(int i = 0; i < len_a; i++)
		for (int j = 0; j < len_b; j++)
		{
			if (A[i] == B[j])
				DP[i + 1][j + 1] = DP[i][j] + 1;
			else
				DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j + 1]);
		}

	cout << DP[len_a][len_b] << '\n';

	while (len_a > 0 && len_b > 0)
	{
		if (DP[len_a][len_b] == DP[len_a - 1][len_b]) len_a--;
		else if (DP[len_a][len_b] == DP[len_a][len_b - 1]) len_b--;
		else 
		{
			len_a--;
			len_b--;
			ans += A[len_a];
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << '\n';

	return 0;
}