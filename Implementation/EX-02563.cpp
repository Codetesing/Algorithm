#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 101

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    bool arr[MAX][MAX] = { false };
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                arr[x + j][y + k] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i][j]) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
