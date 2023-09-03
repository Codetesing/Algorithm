#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;

    int n = s.size();
    set<string> se;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            string t = s.substr(i, j);
            se.insert(t);
        }
    }

    int ans = se.size();
    cout << ans << '\n';

    return 0;
}
