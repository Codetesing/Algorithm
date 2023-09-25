#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> v(N);
    int visited[10001] = { 0 };
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        int p = v[i].first;
        int d = v[i].second;

        for (int j = d; j > 0; j--) {
            if (visited[j] == 0) {
                visited[j] = p;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 10000; i++)
        ans += visited[i];

    cout << ans << '\n';

    return 0;
}
