#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define MAX 100001

using namespace std;

int BFS(int N, int K) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool visited[MAX] = { false };

    pq.push({ 0, N });

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        visited[cur.second] = true;

        if (cur.second == K)
            return cur.first;

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) next = cur.second * 2;
            else if (i == 1) next = cur.second + 1;
            else if (i == 2) next = cur.second - 1;

            if (next < 0 || next >= MAX) continue;
            if (visited[next]) continue;

            if (i == 0) pq.push({ cur.first, next });
            else pq.push({ cur.first + 1, next });
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;

    int res = BFS(N, K);

    cout << res << '\n';

    return 0;
}
