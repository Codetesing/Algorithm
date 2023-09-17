#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] < i) break;
        ans += v[i] - i;
    }

    cout << ans << '\n';

    return 0;
}
