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

    int N; cin >> N;
    map<string, int> m;
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        m[s]++;
    }

    string ans = "";
    int cnt = 0;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second > cnt) {
            ans = it->first;
            cnt = it->second;
        }
    }

    cout << ans << '\n';

    return 0;
}
