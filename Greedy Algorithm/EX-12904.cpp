#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string S; cin >> S;
    string T; cin >> T;

    int flag = 0;
    int sn = S.size() - 1;
    for (int i = T.size() - 1; i >= sn; i--) {
        if (S == T) {
            flag = 1;
            break;
        }

        if (T[i] == 'A') {
            T.pop_back();
        }
        else if (T[i] == 'B') {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    cout << flag << '\n';

    return 0;
}
