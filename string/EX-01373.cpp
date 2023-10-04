#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    string o = "";

    reverse(s.begin(), s.end());

    if (s == "0") o = "0";

    int d = 1, n = 0;
    for (int i = 0; i < s.size(); i++) {
        n += d * (s[i] - '0');
        d *= 2;

        if (i % 3 == 2) {
            o += to_string(n);
            d = 1;
            n = 0;
        }
    }

    if (n != 0) {
        o += to_string(n);
    }
    reverse(o.begin(), o.end());
    cout << o << '\n';

    return 0;
}
