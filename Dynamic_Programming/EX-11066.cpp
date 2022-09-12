#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int t;
int dp[501][501];
int sum[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }

        for (int i = 1; i < k; i++) {
            for (int x = 1; x <= k - i; x++) {
                int y = x + i;
                dp[x][y] = INF;

                for (int mid = x; mid < y; mid++) {
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
    return 0;
}