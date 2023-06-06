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

    int res = 0;
    if (N == 1)
        res = 1;
    else if (N == 2)
        res = min((M - 1) / 2 + 1, 4);
    else {
        if (M >= 7)
            res = M - 2;
        else
            res = min(4, M);
    }

    cout << res << '\n';

    return 0;
}
