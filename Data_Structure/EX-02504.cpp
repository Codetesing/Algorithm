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
    int ans = 0, mul = 1;
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
            mul *= 2;
        }
        else if (s[i] == '[') {
            st.push(s[i]);
            mul *= 3;
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }
            if(s[i - 1] == '(')
                ans += mul;
            mul /= 2;
            st.pop();
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }
            if(s[i - 1] == '[')
                ans += mul;
            mul /= 3;
            st.pop();
        }
    }

    if (!st.empty())
        ans = 0;

    cout << ans << '\n';

    return 0;
}
