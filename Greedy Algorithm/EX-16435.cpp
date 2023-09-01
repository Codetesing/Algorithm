#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, L; cin >> N >> L;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    
    int ans = L;
    for (int i = 0; i < N; i++) {
        if (ans >= v[i])
            ans++;
        else
            break;
    }

    cout << ans << '\n';

    return 0;
}
