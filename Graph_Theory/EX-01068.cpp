#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> v(51);
bool visited[51] = { false };
int cnt = 0, d = 0;

void DFS(int start) {
    if ((v[start].size() == 0) || (v[start].size() == 1 && v[start][0] == d)) {
        cnt++;
        return;
    }

    visited[start] = true;
    for (int i = 0; i < v[start].size(); i++) {
        if (!visited[v[start][i]]) {
            DFS(v[start][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int start = -1, t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t == -1) {
            start = i;
        }
        else {
            v[t].push_back(i);
        }
    }
    cin >> d;
    visited[d] = true;

    if(!visited[start])
        DFS(start);

    int ans = cnt;
    cout << ans << '\n';

    return 0;
}
