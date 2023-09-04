#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct node {
    int next;
    int weight;
} node;

vector<vector<node>> graph(10001);
bool visited[10001] = { false };
int max_len = 0;

void DFS(int start, int len) {
    if (len > max_len)
        max_len = len;

    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++) {
        if (!visited[graph[start][i].next])
            DFS(graph[start][i].next, len + graph[start][i].weight);
    }
    visited[start] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    for(int i = 1; i <= n; i++)
        if (!visited[i])
            DFS(i, 0);

    cout << max_len << '\n';

    return 0;
}
