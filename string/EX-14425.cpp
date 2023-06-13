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

    int N, M; cin >> N >> M;
    string s;
    set<string> s1;
    for (int i = 0; i < N; i++) {
        cin >> s;
        s1.insert(s);
    }

    int res = 0;
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (s1.find(s) != s1.end())
            res++;
    }

    cout << res << '\n';

    return 0;
}
