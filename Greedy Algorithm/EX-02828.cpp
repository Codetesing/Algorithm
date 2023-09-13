#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    int j; cin >> j;

    int left = 1, right = M, t;
    int ans = 0;
    for (int i = 0; i < j; i++) {
        cin >> t;

        if (t < left) {
            ans += left - t;
            right -= left - t;
            left = t;
        }
        else if (t > right) {
            ans += t - right;
            left += t - right;
            right = t;
        }
    }

    cout << ans << '\n';

    return 0;
}
