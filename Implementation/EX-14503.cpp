#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 51

using namespace std;

typedef struct status{
    int x;
    int y;
    int d;
} status;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int arr[MAX][MAX] = { 0 };
    int rx[] = { -1, 0, 1, 0 };
    int ry[] = { 0, 1, 0, -1 };
    int N, M; cin >> N >> M;

    status robot;
    cin >> robot.x >> robot.y >> robot.d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    while (1) {
        int x = robot.x;
        int y = robot.y;
        int d = robot.d;

        if (arr[x][y] == 0) {
            arr[x][y] = 2;
            ans++;
        }

        else {
            bool flag = false;
            int temp = d;

            for (int i = d - 1; ; i--) {
                if (i == -1)
                    i = 3;

                int nx = x + rx[i];
                int ny = y + ry[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if (arr[nx][ny] == 0) {
                    flag = true;
                    robot.x = nx;
                    robot.y = ny;
                    robot.d = i;
                    break;
                }

                if (i == d) break;
            }

            if (!flag) {
                int t = (d + 2) % 4;

                int nx = x + rx[t];
                int ny = y + ry[t];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 1) {
                    break;
                }
                else {
                    robot.x = nx;
                    robot.y = ny;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
