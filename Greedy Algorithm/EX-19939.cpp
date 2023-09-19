#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;

    int ans = 0;
    if (2 * N < K * (K + 1))
        ans = -1;
    else if ((2 * N - (K * (K + 1))) % K == 0)
        ans = K - 1;
    else
        ans = K;

    cout << ans << '\n';

    return 0;
}
