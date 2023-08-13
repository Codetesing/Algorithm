#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    list<char> L;

    for (int i = 0; i < s.size(); i++)
        L.push_back(s[i]);

    list<char>::iterator it = L.end();
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        if (c == 'L') {
            if (it != L.begin())
                it--;
        }
        else if (c == 'D') {
            if (it != L.end())
                it++;
        }
        else if (c == 'B') {
            if (it != L.begin())
                it = L.erase(--it);
        }
        else {
            char t; cin >> t;
            L.insert(it, t);
        }
    }

    for (list<char>::iterator t = L.begin(); t != L.end(); t++)
        cout << *t;
    cout << '\n';

    return 0;
}
