#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N; cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];
        
        long long ans = 0;
        int cur = N - 1;
        for (int i = N - 2; i >= 0; i--) {
            if (v[cur] > v[i])
                ans += v[cur] - v[i];
            else
                cur = i;
        }

        cout << ans << '\n';
    }

    return 0;
}
