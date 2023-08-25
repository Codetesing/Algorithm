#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    map<string, string> m;
    string s, t;
    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        m[s] = t;
    }

    for (int i = 0; i < M; i++) {
        cin >> s;
        cout << m[s] << '\n';
    }

    return 0;
}
