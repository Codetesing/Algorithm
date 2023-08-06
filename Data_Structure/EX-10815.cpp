#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    map<int, bool> m;
    
    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        m[t] = true;
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> t;
        if (m[t])
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }

    return 0;
}
