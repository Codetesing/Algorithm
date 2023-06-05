#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int IS_PELINDROME(string s) {
    string t = s;
    reverse(s.begin(), s.end());

    if (t == s) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;

    cout << IS_PELINDROME(s) << '\n';

    return 0;
}
