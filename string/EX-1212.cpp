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

    if (s == "0") {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
        int div = 4;
        int p = 3;
        int t = s[i] - '0';

        while (div != 0) {
            res.push_back(t / div);
            t %= div;
            div /= 2;
        }
    }

    int i = 0;
    while(res[i] == 0)
        i++;
    for (; i < res.size(); i++)
        cout << res[i];
    cout << '\n';

    return 0;
}
