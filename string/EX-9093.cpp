#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> SPLIT(string s) {
    vector<string> v;

    int i, j;
    for(i = 0, j = 0; i < s.size(); i++)
        if (s[i] == ' ') {
            v.push_back(s.substr(j, i - j));
            j = i + 1;
        }
    v.push_back(s.substr(j, s.size()));

    return v;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    cin.ignore();
    vector<string> s(N);
    for (int i = 0; i < N; i++)
        getline(cin, s[i]);

    vector<string> res;
    for (int i = 0; i < N; i++) {
        vector<string> t = SPLIT(s[i]);

        for (int j = 0; j < t.size(); j++)
            reverse(t[j].begin(), t[j].end());
        
        string temp = "";
        for (int j = 0; j < t.size() - 1; j++)
            temp += t[j] + ' ';
        temp += t[t.size() - 1];

        res.push_back(temp);
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';

    return 0;
}
