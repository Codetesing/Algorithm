#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int X; cin >> X;
    int N; cin >> N;
    int sum = 0, a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        sum += a * b;
    }

    string ans = "Yes";
    if (X != sum) ans = "No";

    cout << ans << '\n';

    return 0;
}
