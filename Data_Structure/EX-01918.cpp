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
    string ans = "";
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]))
            ans += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == '*' || s[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << ans << '\n';

    return 0;
}
