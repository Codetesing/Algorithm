#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N; cin >> N;
		vector<pair<int, int>> score(N);
		
		for (int i = 0; i < N; i++)
			cin >> score[i].first >> score[i].second;;

		sort(score.begin(), score.end(), cmp);

		int min_score = score[0].second;
		int res = 1;
		for (int i = 1; i < N; i++) {
			if (score[i].second < min_score) {
				res++;
				min_score = score[i].second;
			}
		}

		cout << res << '\n';
	}
	
	return 0;
}
