#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> rope(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> rope[i];

	sort(rope.begin() + 1, rope.end(), cmp);

	int result = 0;
	for (int i = 1; i <= N; i++)
		result = max(result, rope[i] * i);

	cout << result << '\n';

	return 0;
}
