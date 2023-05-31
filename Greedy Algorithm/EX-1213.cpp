#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cnt[26] = { 0 };
    string s; cin >> s;
    int N = s.size();

    for (int i = 0; i < N; i++)
        cnt[s[i] - 'A']++;

    string res = "";
    if (N % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                res = "I'm Sorry Hansoo";
                break;
            }
            else
                cnt[i] /= 2;
        }

        if (res == "") {
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < cnt[i]; j++)
                    res += i + 'A';

            string t = res;
            reverse(t.begin(), t.end());
            res += t;
        }
    }
    else {
        char c = NULL;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                if (c == NULL)
                    c = i + 'A';
                else {
                    res = "I'm Sorry Hansoo";
                    break;
                }
            }
            cnt[i] /= 2;
        }

        if (res == "") {
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < cnt[i]; j++)
                    res += i + 'A';

            string t = res;
            reverse(t.begin(), t.end());
            res += c + t;
        }
    }

    cout << res << '\n';

    return 0;
}
