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

    int n, m; cin >> n >> m;
    long long t;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        cin >> t;
        pq.push(t);
    }

    long long a, b;
    for (int i = 0; i < m; i++) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        t = a + b;
        pq.push(t);
        pq.push(t);
    }

    long long res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }

    cout << res << '\n';

    return 0;
}
