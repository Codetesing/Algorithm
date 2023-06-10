#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> v(5);
    int max_len = 0;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        max_len = max(max_len, (int)v[i].size());
    }

    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < 5; j++) {
            if (v[j].size() <= i)
                continue;
            cout << v[j][i];
        }
    }
    cout << '\n';

    return 0;
}
