#include <iostream>
#include <string>

#define M 1234567891
#define r 31

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int L; cin >> L;
	string s; cin >> s;

	long long t = 1;
	long long res = 0;
	for (int i = 0; i < L; i++) {
		int n = s[i] - 'a' + 1;
		res = (res + (n * t)) % M;
		t = (t * r) % M;
	}

	cout << res << '\n';

	return 0;
}
