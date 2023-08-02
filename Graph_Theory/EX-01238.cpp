#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;

vector<pair<int, int>> g[1001];

int dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int d[1001];
    fill(d, d + 1001, INF);
    
    pq.push({ 0 , start });
    d[start] = 0;

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur_cost > d[cur]) continue;

        for (int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i].first;
            int next_cost = g[cur][i].second;

            if (cur_cost + next_cost < d[next]) {
                d[next] = cur_cost + next_cost;
                pq.push({ d[next], next });
            }
        }
    }

    return d[end];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, X; cin >> N >> M >> X;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        g[a].push_back({ b, c });
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int go = dijkstra(i, X);
        int come = dijkstra(X, i);
        ans = max(ans, go + come);
    }

    cout << ans << '\n';

    return 0;
}
