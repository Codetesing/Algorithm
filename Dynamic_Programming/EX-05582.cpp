#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b; cin >> a >> b;

    int DP[4001][4001] = { 0 };
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                DP[i + 1][j + 1] = DP[i][j] + 1;
                ans = max(ans, DP[i + 1][j + 1]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
