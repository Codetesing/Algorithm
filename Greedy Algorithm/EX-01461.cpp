#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> minus(1, 0);
    vector<int> plus(1, 0);

    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t < 0)
            minus.push_back(t * -1);
        else
            plus.push_back(t);
    }

    sort(minus.begin(), minus.end(), greater<int>());
    sort(plus.begin(), plus.end(), greater<int>());

    int mi = 0, pi = 0;
    int ans = 0;
    if (minus[0] > plus[0]) {
        ans += minus[0];
        mi += M;
    }
    else {
        ans += plus[0];
        pi += M;
    }

    for (int i = mi; i < minus.size(); i += M) {
        ans += minus[i] * 2;
    }

    for (int i = pi; i < plus.size(); i += M) {
        ans += plus[i] * 2;
    }

    cout << ans << '\n';

    return 0;
}
