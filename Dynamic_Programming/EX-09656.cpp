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
    string s = "SK";

    if (N % 2 == 1)
        s = "CY";

    cout << s << '\n';

    return 0;
}
