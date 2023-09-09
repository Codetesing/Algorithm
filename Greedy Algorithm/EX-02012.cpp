#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> cnt(N);
    for (int i = 0; i < N; i++)
        cin >> cnt[i];

    sort(cnt.begin(), cnt.end());

    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += abs((i + 1) - cnt[i]);

    cout << ans << '\n';

    return 0;
}
