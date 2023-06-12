#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = 8;
    vector<string> m(N);
    for (int i = 0; i < N; i++)
        cin >> m[i];

    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = i % 2; j < N; j += 2)
            if (m[i][j] == 'F')
                res++;

    cout << res << '\n';

    return 0;
}
