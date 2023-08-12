#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    stack<char> st;
    int res = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') 
            st.push(s[i]);
        else {
            st.pop();
            if (s[i - 1] == ')')
                res += 1;
            else
                res += st.size();
        }
    }

    cout << res << '\n';

    return 0;
}
