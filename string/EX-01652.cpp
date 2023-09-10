#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < N; i++) {
        int t = 0;
        for (int j = 0; j < N; j++) {
            if (v[i][j] == 'X') 
                t = 0;
            else
                t++;

            if (t >= 2) {
                ans1++;
                while (j < N && v[i][j] == '.')
                    j++;
                j--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int t = 0;
        for (int j = 0; j < N; j++) {
            if (v[j][i] == 'X')
                t = 0;
            else
                t++;

            if (t >= 2) {
                ans2++;
                while (j < N && v[j][i] == '.')
                    j++;
                j--;
            }
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}
