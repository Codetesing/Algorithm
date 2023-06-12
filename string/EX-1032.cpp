#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++)
        cin >> s[i];

    string res = "";
    for (int i = 0; i < s[0].size(); i++) {
        bool flag = false;
        for (int j = 1; j < N; j++) {
            if (s[0][i] != s[j][i]) {
                flag = true;
                break;
            }
        }
        if (flag)
            res += '?';
        else
            res += s[0][i];
    }

    cout << res << '\n';

    return 0;
}
