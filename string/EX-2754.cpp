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
    
    string res = "";
    if (s.size() == 1)
        res = "0.0";
    else {
        if (s[0] == 'A')
            res += '4';
        else if (s[0] == 'B')
            res += '3';
        else if (s[0] == 'C')
            res += '2';
        else if (s[0] == 'D')
            res += '1';
        
        res += '.';

        if (s[1] == '+')
            res += '3';
        else if (s[1] == '0')
            res += '0';
        else if (s[1] == '-') {
            res[0]--;
            res += '7';
        }
    }

    cout << res << '\n';

    return 0;
}
