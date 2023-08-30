#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<string> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    string ans = "";
    int min_val = 0;
    for (int i = 0; i < M; i++) {
        map<char, int> m;
        for (int j = 0; j < N; j++) {
            m[v[j][i]]++;
        }

        int cnt = 0;
        char t;
        for (auto it : m) {
            if (cnt < it.second) {
                t = it.first;
                cnt = it.second;
            }
        }
        ans += t;
        min_val += N - cnt;
    }

    cout << ans << '\n';
    cout << min_val << '\n';

    return 0;
}
