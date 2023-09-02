#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    for (int t = 0; t < tc; t++) {
        int N; cin >> N;
        vector<int> L(N);
        for (int i = 0; i < N; i++)
            cin >> L[i];

        sort(L.begin(), L.end());

        int ans = 0;
        for (int i = 0; i < N - 2; i++)
            ans = max(L[i + 2] - L[i], ans);

        cout << ans << '\n';
    }

    return 0;
}
