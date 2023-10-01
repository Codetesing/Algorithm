#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int R, C; cin >> R >> C;
    vector<string> v(R);
    for (int i = 0; i < R; i++)
        cin >> v[i];

    queue<pair<int, int>> q;
    pair<int, int> end;
    int visited[51][51] = { 0 };
    int rotate_x[] = { -1, 0, 0, 1 };
    int rotate_y[] = { 0, -1, 1, 0 };

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] == 'S') {
                q.push({ i, j });
                visited[i][j] = 1;
                break;
            }
        }
        if (!q.empty()) {
            break;
        }
    }

    int ans = -1;
    int time = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (visited[x][y] == time + 1) {
            bool temp[51][51] = { false };
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (!temp[i][j] && v[i][j] == '*') {
                        for (int k = 0; k < 4; k++) {
                            int next_x = i + rotate_x[k];
                            int next_y = j + rotate_y[k];
                            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C)
                                continue;
                            if (v[next_x][next_y] == '.' && !temp[next_x][next_y]) {
                                v[next_x][next_y] = '*';
                                temp[next_x][next_y] = true;
                            }
                        }
                    }
                }
            }
            time++;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = x + rotate_x[i];
            int next_y = y + rotate_y[i];

            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C)
                continue;

            if (!visited[next_x][next_y] && v[next_x][next_y] == '.') {
                q.push({ next_x, next_y });
                visited[next_x][next_y] = visited[x][y] + 1;
            }
            if (v[next_x][next_y] == 'D') {
                ans = visited[x][y];
                break;
            }
        }

        if (ans != -1) {
            break;
        }
    }

    if (ans == -1)
        cout << "KAKTUS" << '\n';
    else
        cout << ans << '\n';

    return 0;
}
