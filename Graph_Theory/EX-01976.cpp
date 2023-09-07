#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int graph[201][201] = { 0 };
bool visited[201] = { false };
int N;

void DFS(int start, int end) {
    visited[start] = true;
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && graph[start][i] == 1)
            DFS(i, end);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> trip(M);
    for (int i = 0; i < M; i++)
        cin >> trip[i];

    string ans = "YES";
    for (int i = 0; i < M - 1; i++) {
        DFS(trip[i], trip[i + 1]);

        if (!visited[trip[i + 1]]) {
            ans = "NO";
            break;
        }

        for (int i = 1; i <= N; i++)
            visited[i] = false;
    }

    cout << ans << '\n';

    return 0;
}
