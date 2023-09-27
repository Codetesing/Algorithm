#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char c[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	while (1) {
		string s; getline(cin, s);
		if (s == "#")
			break;

		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < 10; j++) {
				if (s[i] == c[j]) {
					ans++;
					break;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
