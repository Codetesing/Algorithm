#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef struct node {
	char c;
	int count;
} node;

bool cmp(node a, node b) {
	return a.count > b.count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	vector<node> v2;
	v2.push_back({ '-', 0 });
	int ind[26] = { 0 };
	int cnt = 1;

	for (int i = 0; i < N; i++) {
		int mul = 1;
		
		for (int j = v[i].size() - 1; j >= 0; j--) {
			int c = v[i][j] - 'A';
			if (ind[c]) 
				v2[ind[c]].count += mul;
			else {
				v2.push_back({ v[i][j], mul });
				ind[c] = cnt++;
			}
			mul *= 10;
		}
	}

	sort(v2.begin() + 1, v2.end(), cmp);

	map<char, char> m;
	char temp = '9';
	for (int i = 1; i < v2.size(); i++) {
		m[v2[i].c] = temp;
		temp--;
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		string s = "";
		for (int j = 0; j < v[i].size(); j++)
			s += m[v[i][j]];
		res += stoi(s);
	}
	
	cout << res << '\n';

	return 0;
}
