#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long N, M; cin >> N >> M;

    long long ans = N > M ? N - M : M - N;

    cout << ans << '\n';

    return 0;
}
