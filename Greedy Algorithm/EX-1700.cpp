#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;
	vector<int> v(K);
	vector<int> multi;
	for (int i = 0; i < K; i++)
		cin >> v[i];

	int res = 0;
	for (int i = 0; i < K; i++) {
		if (find(multi.begin(), multi.end(), v[i]) != multi.end())
			continue;

		if (multi.size() != N)
			multi.push_back(v[i]);
		else {
			int max_ind = K;
			int max_value = 0;
			for (int j = 0; j < N; j++) {
				int ind = find(v.begin() + i + 1, v.end(), multi[j]) - v.begin();
				if (ind == K) {
					max_ind = j;
					break;
				}
				else {
					if (max_value < ind) {
						max_value = ind;
						max_ind = j;
					}
				}
			}

			multi[max_ind] = v[i];
			res++;
		}
	}

	cout << res << '\n';

	return 0;
}
