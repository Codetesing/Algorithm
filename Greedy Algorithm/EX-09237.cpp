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
    vector<int> v(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    sort(v.begin() + 1, v.end(), greater<int>());

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, i + v[i]);
    ans++;

    cout << ans << '\n';

    return 0;
}
