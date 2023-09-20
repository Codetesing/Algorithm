#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c; cin >> a >> b >> c;

    string ans;
    if (a + b + c != 180)
        ans = "Error";
    else {
        if (a == 60 && b == 60 && c == 60)
            ans = "Equilateral";
        else if (a != b && b != c && c != a)
            ans = "Scalene";
        else
            ans = "Isosceles";
    }

    cout << ans << '\n';

    return 0;
}
