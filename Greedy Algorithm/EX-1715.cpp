#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int &a, int &b) {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	priority_queue<int, vector<int>, cmp> pq;
	
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		pq.push(t);
	}


	long long s = 0;
	while (pq.size() >= 2) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		s += a + b;
		pq.push(a + b);
	}

	cout << s << '\n';

	return 0;
}
