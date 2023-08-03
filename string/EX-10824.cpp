#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int A, B, C, D; cin >> A >> B >> C >> D;
    string a = to_string(A) + to_string(B);
    string b = to_string(C) + to_string(D);

    long long res = stoll(a) + stoll(b);
    cout << res << endl;

    return 0;
}
