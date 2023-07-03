#include <iostream>
#include <string>

using namespace std;

int main() {

	string N;
	int B;

	cin >> N >> B;

	int res = 0, mul = 1;
	for (int i = N.size() - 1; i >= 0; i--) {
		int t;

		if (isalpha(N[i]))
			t = N[i] - 'A' + 10;
		else
			t = N[i] - '0';

		res += t * mul;
		mul *= B;
	}

	cout << res << '\n';

	return 0;
}
