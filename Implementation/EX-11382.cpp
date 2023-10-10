#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    long long A, B, C; cin >> A >> B >> C;
    
    long long ans = A + B + C;
    cout << ans << '\n';

    return 0;
}
