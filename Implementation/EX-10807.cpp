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
    int cnt[201] = { 0 };
    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        cnt[t + 100]++;
    }

    cin >> t;
    cout << cnt[t + 100] << '\n';

    return 0;
}
