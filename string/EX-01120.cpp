#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    if (a.size() > b.size())
        swap(a, b);

    int ans = 51;
    for (int i = 0; i <= b.size() - a.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[i + j])
                cnt++;
        }
        ans = min(cnt, ans);
    }

    cout << ans << '\n';

    return 0;
}
