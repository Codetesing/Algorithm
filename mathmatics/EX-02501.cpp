#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;

    int ans = 0, cnt = 0, val = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            cnt++;
            val = i;
        }

        if (cnt == K)
            break;
    }

    if (cnt == K)
        ans = val;

    cout << ans << '\n';

    return 0;
}
