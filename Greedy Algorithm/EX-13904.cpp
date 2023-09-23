#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    bool visited[1001] = { false };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int d, w;
    for (int i = 0; i < N; i++) {
        cin >> d >> w;
        pq.push({ d, w });
    }

    int ans = 0;
    while (!pq.empty()) {
        d = pq.top().first;
        w = pq.top().second;
        pq.pop();

        for (int i = d; i >= 1; i--) {
            if (!visited[i]) {
                visited[i] = true;
                ans += w;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
