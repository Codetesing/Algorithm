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
    string s; cin >> s;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] != 'P') continue;

        for (int j = i - K; j <= i + K; j++) {
            if (j < 0 || j >= N) continue;

            if (s[j] == 'H') {
                s[j] = '-';
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
