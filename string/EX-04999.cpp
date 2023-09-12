#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2; cin >> s1 >> s2;

    string ans = "go";
    if (s1.size() < s2.size())
        ans = "no";

    cout << ans << '\n';

    return 0;
}
