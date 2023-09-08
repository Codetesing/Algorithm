#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool can_ucpc(string s, int ind) {
    char cs[] = { 'C', 'P', 'C' };
    int j = 0;

    for (int i = ind + 1; i < s.size(); i++) {
        if (s[i] == cs[j]) {
            j++;
        }
        if (j == 3) {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; getline(cin, s);
    
    string ans = "I hate UCPC";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'U' && can_ucpc(s, i)) {
            ans = "I love UCPC";
        }
    }

    cout << ans << '\n';

    return 0;
}
