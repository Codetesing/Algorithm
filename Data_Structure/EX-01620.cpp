#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    map<string, int> m1;
    vector<string> m2;

    string t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        m1[t] = i + 1;
        m2.push_back(t);
    }

    for (int i = 0; i < M; i++) {
        cin >> t;
        if (t[0] > '0' && t[0] <= '9')
            cout << m2[stoi(t) - 1] << '\n';
        else
            cout << m1[t] << '\n';
    }

    return 0;
}
