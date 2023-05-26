#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int A, B; cin >> A >> B;
	
	int cnt = 1;
	while (A != B && B != 0) {
		if (B % 10 == 1)
			B /= 10;
		else if (B % 2 == 0)
			B /= 2;
		else
			B = 0;
		cnt++;
	}

	if (B == 0)
		cnt = -1;

	cout << cnt << '\n';

	return 0;
}
