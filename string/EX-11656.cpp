#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;

	vector<string> res;
	for (int i = 0; i < s.size(); i++)
		res.push_back(s.substr(i, s.size() - i));

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << '\n';

	return 0;
}
