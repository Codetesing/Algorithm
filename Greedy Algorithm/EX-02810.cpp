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
    string s; cin >> s;

    int ans = N + 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L' && s[i - 1] == 'L') {
            ans--;
            i++;
        }
    }
    ans = min(ans, N);

    cout << ans << '\n';

    return 0;
}
