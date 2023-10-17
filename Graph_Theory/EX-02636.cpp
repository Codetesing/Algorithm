#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define MAX 101

using namespace std;

int N, M;
int arr[MAX][MAX] = { 0 };
int rx[] = { -1, 0, 0, 1 };
int ry[] = { 0, 1, -1, 0 };
bool visited[MAX][MAX] = { false };

void DFS(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + rx[i];
        int ny = y + ry[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        if (!visited[nx][ny] && arr[nx][ny] == 0) DFS(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) cnt++;
        }
    }

    DFS(0, 0);

    int ans1 = 0;
    int ans2 = 0;
    while (cnt != 0) {
        queue<pair<int, int>> q;

        ans1++;
        ans2 = cnt;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + rx[k];
                        int ny = j + ry[k];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;

                        if (visited[nx][ny]) {
                            q.push({ i, j });
                            break;
                        }
                    }
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            cnt--;

            visited[x][y] = true;
            arr[x][y] = 0;

            for (int k = 0; k < 4; k++) {
                int nx = x + rx[k];
                int ny = y + ry[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;

                if (!visited[nx][ny] && arr[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    DFS(nx, ny);
                    break;
                }
            }
        }
    }

    cout << ans1 << '\n';
    cout << ans2 << '\n';

    return 0;
}
