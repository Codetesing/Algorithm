#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int K; cin >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    vector<int> v2;
    for (int i = 1; i < N; i++)
        v2.push_back(v[i] - v[i - 1]);

    sort(v2.begin(), v2.end());

    int res = 0;
    for (int i = 0; i < N - K; i++)
        res += v2[i];

    cout << res << '\n';

    return 0;
}
