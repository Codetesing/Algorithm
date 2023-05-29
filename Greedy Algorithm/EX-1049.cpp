#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	
	vector<int> v1(M);
	vector<int> v2(M);
	for (int i = 0; i < M; i++)
		cin >> v1[i] >> v2[i];

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int t = min(v1[0] * ((N / 6) + 1), v2[0] * N);
	t = min(t, v1[0] * (N / 6) + v2[0] * (N % 6));

	cout << t << '\n';

	return 0;
}
