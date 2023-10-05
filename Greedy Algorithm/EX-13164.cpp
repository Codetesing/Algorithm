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
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    int ans = v[0] - v[N - 1];
    for (int i = 0; i < N - 1; i++)
        v[i] = v[i] - v[i + 1];
    v[N - 1] = 0;
    
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; K > 1; K--, i++)
        ans -= v[i];

    cout << ans << '\n';

    return 0;
}
