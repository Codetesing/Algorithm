#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, I; cin >> A >> I;
    int ans = A * (I - 1) + 1;

    cout << ans << '\n';

    return 0;
}
