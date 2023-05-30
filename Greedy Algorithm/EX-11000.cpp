#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

bool cmp2(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), cmp2);

    priority_queue<int, vector<int>, cmp> pq;
    pq.push(v[0].second);

    for (int i = 1; i < N; i++) {
        int t = pq.top();

        if (t <= v[i].first)
            pq.pop();

        pq.push(v[i].second);
    }

    int res = pq.size();
    cout << res << '\n';

    return 0;
}
