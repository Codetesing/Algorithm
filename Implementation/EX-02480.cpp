#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int A, B, C; cin >> A >> B >> C;
    
    int ans = 0;
    if (A == B && B == C)
        ans = 10000 + A * 1000;
    else if (A == B)
        ans = 1000 + A * 100;
    else if (B == C)
        ans = 1000 + B * 100;
    else if (C == A)
        ans = 1000 + C * 100;
    else
        ans = max(max(A, B), C) * 100;

    cout << ans << '\n';

    return 0;
}
