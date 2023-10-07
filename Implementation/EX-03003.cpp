#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int chess[] = { 1, 1, 2, 2, 2, 8 };
    int t[6];

    for (int i = 0; i < 6; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < 6; i++) {
        cout << chess[i] - t[i] << ' ';
    }
    cout << '\n';

    return 0;
}
