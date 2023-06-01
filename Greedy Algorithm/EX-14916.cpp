#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int cnt = n / 5;
    n %= 5;

    if (n % 2 == 0)
        cnt += n / 2;
    else {
        if (cnt != 0)
            cnt = cnt - 1 + ((5 + n) / 2);
        else
            cnt = -1;
    }
    cout << cnt << '\n';

    return 0;
}
