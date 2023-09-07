#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; getline(cin, s);
    string f; getline(cin, f);

    int n1 = s.size(), n2 = f.size();
    int ans = 0;

    for (int i = 0; i <= s.size() - f.size(); i++) {
        string t = s.substr(i, n2);

        if (t == f) {
            ans++;
            s.erase(s.begin() + i, s.begin() + i + n2);
            i--;
        }

        if (s.size() < n2)
            break;
    }

    cout << ans << '\n';

    return 0;
}
