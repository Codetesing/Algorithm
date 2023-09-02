#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int rx[] = { -1, 0, 0, 1 };
int ry[] = { 0, 1, -1, 0 };
int graph[301][301] = { 0 };
bool visited[301][301] = { false };
int N, M, cnt;

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = false;
}

void next_year() {
    int temp[301][301] = { 0 };
        
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0)
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int next_x = i + rx[k];
                int next_y = j + ry[k];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
                    continue;

                if (graph[next_x][next_y] == 0)
                    cnt++;
            }

            if (graph[i][j] - cnt < 0)
                temp[i][j] = 0;
            else
                temp[i][j] = graph[i][j] - cnt;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(graph[i][j] != 0)
                graph[i][j] = temp[i][j];
        }
    }
}

void DFS(int r, int c) {
    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int next_r = r + rx[i];
        int next_c = c + ry[i];

        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M)
            continue;

        if (!visited[next_r][next_c] && graph[next_r][next_c] != 0)
            DFS(next_r, next_c);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];

    int ans = 0;
    while (1) {
        init();
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && graph[i][j] != 0) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        if (cnt == 0 || cnt >= 2)
            break;

        ans++;
        next_year();
    }

    if (cnt == 0)
        ans = 0;
    cout << ans << '\n';

    return 0;
}
