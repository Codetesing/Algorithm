#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long S; cin >> S;
	
	int N;
	for (N = 1; S >= N; N++)
		S -= N;

	cout << N - 1 << '\n';

	return 0;
}
