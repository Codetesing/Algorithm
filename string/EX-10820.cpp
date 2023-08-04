#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    while (getline(cin, s)) {
        int cnt[4] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                cnt[3]++;
            else if (isalpha(s[i])) {
                if (islower(s[i]))
                    cnt[0]++;
                else
                    cnt[1]++;
            }
            else
                cnt[2]++;
        }

        for (int i = 0; i < 3; i++)
            cout << cnt[i] << ' ';
        cout << cnt[3] << endl;
    }

    return 0;
}
