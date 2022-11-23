#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string in, bomb;
	cin >> in >> bomb;

	vector<char> s;
	int n = bomb.size();

	for (int i = 0; i < in.size(); i++) {
		s.push_back(in[i]);

		if (s.size() >= n) {
			bool flag = true;
			for (int j = 0; j < bomb.size(); j++) {
				if (s[s.size() - bomb.size() + j] != bomb[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				for (int j = 0; j < n; j++)
					s.pop_back();

		}
	}

	if (s.size() == 0)
		cout << "FRULA";
	else {
		for (int i = 0; i < s.size(); i++)
			cout << s[i];
	}

	return 0;
}