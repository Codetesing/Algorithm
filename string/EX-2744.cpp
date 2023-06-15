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
    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i]))
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
    
    cout << s << '\n';

    return 0;
}
