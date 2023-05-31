#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, L; cin >> N >> L;
    vector<int> pos(N);
    for (int i = 0; i < N; i++)
        cin >> pos[i];

    sort(pos.begin(), pos.end());

    int res = 1;
    int cur = pos[0] + L;
    for (int i = 1; i < N; i++) {
        if (cur <= pos[i]) {
            res++;
            cur = pos[i] + L;
        }
    }

    cout << res << '\n';

    return 0;
}
