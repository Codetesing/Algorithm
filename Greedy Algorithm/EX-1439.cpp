#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string S; cin >> S;
	map<char, int> m;
	int n = S.size();

	for (int i = 0; i < n; i++) {
		int j = i + 1;
		for (; j < n; j++)
			if (S[i] != S[j])
				break;
		m[S[i]]++;
		i = j - 1;
	}

	int cnt = min(m['0'], m['1']);
	cout << cnt << '\n';

	return 0;
}
