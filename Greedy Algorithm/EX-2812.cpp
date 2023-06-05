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

    int N, K; cin >> N >> K;
    string s; cin >> s;

    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        while (!st.empty() && st.top() < s[i] && cnt < K) {
            st.pop();
            cnt++;
        }
        st.push(s[i]);
    }

    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    res = res.substr(0, N - K);

    cout << res << '\n';

    return 0;
}
