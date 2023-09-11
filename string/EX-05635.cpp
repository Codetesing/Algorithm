#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

vector<string> SPLIT(string s, char d) {
    vector<string> v;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, d))
        v.push_back(temp);

    return v;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    cin.ignore();
    vector<vector<string>> v;
    string s;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        v.push_back(SPLIT(s, ' '));
    }

    map<string, string> m;
    for (int i = 0; i < n; i++) {
        s = v[i][3];
        
        if (v[i][2].size() == 1)
            s += "0";
        s += v[i][2];

        if (v[i][1].size() == 1)
            s += "0";
        s += v[i][1];

        m[s] = v[i][0];
    }

    string ans1, ans2;
    ans1 = m.rbegin()->second;
    ans2 = m.begin()->second;

    cout << ans1 << '\n';
    cout << ans2 << '\n';

    return 0;
}
