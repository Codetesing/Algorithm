#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<string> v1(N);
    vector<string> v2(M);
    for (int i = 0; i < N; i++)
        cin >> v1[i];
    for (int i = 0; i < M; i++)
        cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<string> res;
    for (int i = 0; i < N; i++) {
        if (binary_search(v2.begin(), v2.end(), v1[i]))
            res.push_back(v1[i]);
    }

    cout << res.size() << '\n';
    for (auto i : res)
        cout << i << '\n';

    return 0;
}
