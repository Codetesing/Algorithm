#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void st_print(stack<char>& st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);

    string o = "";
    stack<char> st;
    bool t = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            st_print(st);
            t = true;
            cout << s[i];
        }
        else if (s[i] == '>') {
            t = false;
            cout << s[i];
        }
        else if (t) {
            cout << s[i];
        }
        else {
            if (s[i] == ' ') {
                st_print(st);
                cout << s[i];
            }
            else {
                st.push(s[i]);
            }
        }
    }
    st_print(st);
    cout << endl;

    return 0;
}
