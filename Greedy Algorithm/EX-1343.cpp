#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int find_seq(string s, int ind) {
    int cnt = 0;
    for (; ind + cnt < s.size() && cnt < 4; cnt++)
        if (s[ind + cnt] == '.')
            return cnt;

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;

    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.')
            res += s[i];
        else {
            int cnt = find_seq(s, i);

            if (cnt == 4)
                res += "AAAA";
            else if (cnt == 2)
                res += "BB";
            else {
                res = "-1";
                break;
            }

            i += cnt - 1;
        }
    }

    cout << res << '\n';

    return 0;
}
