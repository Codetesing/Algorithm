#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define INF 7654321
#define MAX 801

using namespace std;

int graph[MAX][MAX] = { 0 };
int d[MAX];
int N, E;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};

int dijkstra(int start, int end) {
    for (int i = 1; i <= N; i++)
        d[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({ 0, start });
    d[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 1; i <= N; i++) {
            if (graph[cur][i] != 0 && (d[i] > d[cur] + graph[cur][i])) {
                d[i] = d[cur] + graph[cur][i];
                pq.push({ d[i], i });
            }
        }
    }

    return d[end];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> E;
    int a, b, c, v1, v2;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    cin >> v1 >> v2;

    int n1 = 0, n2 = 0;

    n1 += dijkstra(1, v1);
    n1 += dijkstra(v1, v2);
    n1 += dijkstra(v2, N);

    n2 += dijkstra(1, v2);
    n2 += dijkstra(v2, v1);
    n2 += dijkstra(v1, N);

    int ans = min(n1, n2);
    if (ans >= INF)
        ans = -1;

    cout << ans << '\n';

    return 0;
}
