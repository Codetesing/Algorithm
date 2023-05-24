#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string N; cin >> N;

	int cnt[10] = { 0 };
	for (int i = 0; i < N.size(); i++)
		cnt[N[i] - '0']++;

	int s = 0;
	for (int i = 0; i < 10; i++)
		s += cnt[i] * i;

	if (cnt[0] == 0 || s % 3 != 0)
		N = "-1";
	else
		sort(N.begin(), N.end(), cmp);

	cout << N << '\n';

	return 0;
}
