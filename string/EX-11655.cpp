#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            int t;
            if (s[i] <= 'Z') {
                t = s[i] + 13;
                if (t > 'Z')
                    t = t - 'Z' + 'A' - 1;
            }
            else {
                t = s[i] + 13;
                if (t > 'z')
                    t = t - 'z' + 'a' - 1;
            }
            s[i] = t;
        }
    }

    cout << s << endl;

    return 0;
}
