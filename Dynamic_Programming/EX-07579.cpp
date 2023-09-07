#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX_COST 10001

using namespace std;

typedef struct app {
    int memory;
    int cost;
} app;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<app> v(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i].memory;
    for (int i = 1; i <= N; i++)
        cin >> v[i].cost;

    int DP[101][MAX_COST] = { 0 };
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < MAX_COST; j++) {
            if (v[i].cost > j)
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - v[i].cost] + v[i].memory);
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX_COST; i++) {
        if (DP[N][i] >= M) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
