#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int tc = 1; ; tc++) {
		int L, P, V; cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0)
			break;
		
		long long t = (long long)(V / P) * L;
		t += L > V % P ? V % P : L;

		cout << "Case " << tc << ": " << t << '\n';
	}

	return 0;
}
