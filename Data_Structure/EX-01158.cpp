#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, K; cin >> N >> K;
    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    vector<int> v;
    while (!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        v.push_back(q.front());
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < v.size() - 1; i++)
        cout << v[i] << ", ";
    cout << v.back() << '>' << endl;

    return 0;
}
