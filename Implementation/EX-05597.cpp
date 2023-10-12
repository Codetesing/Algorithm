#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    bool visited[31] = { false };
    int t;
    for (int i = 0; i < 28; i++) {
        cin >> t;
        visited[t] = true;
    }

    for (int i = 1; i <= 30; i++) {
        if (!visited[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
