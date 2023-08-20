#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1000001] = { 0 };

int FIND(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = FIND(parent[a]);
}

void UNION(int a, int b) {
	a = FIND(a);
	b = FIND(b);

	if (a != b)
		parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	int t, a, b;
	for (int i = 0; i < m; i++) {
		cin >> t >> a >> b;

		if (t == 0) {
			UNION(a, b);
		}
		else {
			if (FIND(a) == FIND(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}
