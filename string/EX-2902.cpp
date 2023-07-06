#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;

	string res = "";
	res += s[0];
	for (int i = 1; i < s.size(); i++)
		if (s[i] == '-')
			res += s[i + 1];

	cout << res << '\n';

	return 0;
}
