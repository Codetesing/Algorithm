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

    int N; cin >> N;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    
    int cur = v[1];
    priority_queue<pair<int, int>> pq;
    
    for (int i = 2; i <= N; i++)
        pq.push({ v[i], i });

    int ans = 0;
    while (!pq.empty()) {
        if (pq.top().first < cur)
            break;

        pair<int, int> t = pq.top();
        pq.pop();
        t.first--;
        cur++;
        ans++;
        pq.push(t);
    }

    cout << ans << '\n';

    return 0;
}
