#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	set<string> s;
	string name, opt;
	for (int i = 0; i < n; i++) {
		cin >> name >> opt;

		if (opt == "enter")
			s.insert(name);
		else
			if (s.find(name) != s.end())
				s.erase(name);
	}

	vector<string> ans;
	for (auto i : s)
		ans.push_back(i);

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << '\n';

	return 0;
}
