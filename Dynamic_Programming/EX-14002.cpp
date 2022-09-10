#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PRINT(vector<int> p, int ind, vector<int> arr) {

	if (ind == -1)
		return;

	PRINT(p, p[ind], arr);
	cout << arr[ind] << ' ';
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N, 0);
	vector<int> DP(N, 1);
	vector<int> parent(N, -1);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 1; i < N; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && DP[i] < DP[j] + 1)
			{
				DP[i] = DP[j] + 1;
				parent[i] = j;
			}

	int max_ind = max_element(DP.begin(), DP.end()) - DP.begin();
	int max_val = arr[max_ind];

	cout << DP[max_ind] << '\n';

	PRINT(parent, max_ind, arr);
	cout << '\n';

	return 0;
}