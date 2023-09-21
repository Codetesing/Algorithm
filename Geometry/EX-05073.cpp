#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {

        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());

        if (v[0] == 0 && v[1] == 0 && v[2] == 0)
            break;

        string ans;
        if (v[2] >= v[1] + v[0])
            ans = "Invalid";

        else if (v[0] != v[1] && v[1] != v[2] && v[2] != v[0])
            ans = "Scalene";
        else if (v[0] == v[1] && v[1] == v[2] && v[2] == v[0])
            ans = "Equilateral";
        else
            ans = "Isosceles";

        cout << ans << '\n';
    }

    return 0;
}
