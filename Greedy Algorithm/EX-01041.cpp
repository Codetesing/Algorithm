#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long N; cin >> N;
    vector<int> v(6);
    for (int i = 0; i < 6; i++)
        cin >> v[i];

    long long ans = 0;
    if (N == 1) {
        for (int i = 0; i < 6; i++)
            ans += v[i];
        ans -= *max_element(v.begin(), v.end());
    }
    else {
        v[0] = min(v[0], v[5]);
        v[1] = min(v[1], v[4]);
        v[2] = min(v[2], v[3]);
        sort(v.begin(), v.begin() + 3);

        ans += (v[0] + v[1] + v[2]) * 4;
        ans += (v[0] + v[1]) * (long long)(4 * (N - 2) + 4 * (N - 1));
        ans += v[0] * (long long)((long long)4 * (N - 1) * (N - 2) + (long long)(N - 2) * (N - 2));
    }

    cout << ans << endl;

    return 0;
}
