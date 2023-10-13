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
    N /= 4;

    string ans = "";
    for (int i = 0; i < N; i++)
        ans += "long ";
    ans += "int";

    cout << ans << '\n';

    return 0;
}
