#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp_desc(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A.begin(), A.end(), cmp_desc);
	sort(B.begin(), B.end());

	int S = 0;
	for (int i = 0; i < N; i++)
		S += A[i] * B[i];

	cout << S << '\n';
	
	return 0;
}
