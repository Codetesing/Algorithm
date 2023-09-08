#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < M - 2; i++) {
        int cnt = 0;
        if (s[i] == 'I') {
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                cnt++;

                if (cnt == N) {
                    ans++;
                    cnt--;
                }
                i += 2;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
