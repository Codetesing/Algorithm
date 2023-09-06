#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct NODE {
    bool check;
    NODE* next[10];

    NODE() {
        check = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }

    void insert(string s, int ind) {
        if (ind == s.size()) {
            check = true;
            return;
        }
        
        int cur = s[ind] - '0';
        if (next[cur] == NULL)
            next[cur] = new NODE();

        next[cur]->insert(s, ind + 1);
    }

    bool find_node(string s, int ind) {
        if (ind == s.size())
            return true;
        if (check)
            return false;

        int cur = s[ind] - '0';
        return next[cur]->find_node(s, ind + 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    for (int t = 0; t < tc; t++) {
        int n; cin >> n;

        NODE* root = new NODE();
        vector<string> s(n);
        string ans = "YES";
        bool flag = false;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            root->insert(s[i], 0);
        }
        for (int i = 0; i < n; i++) {
            if (!(root->find_node(s[i], 0))) {
                flag = true;
                break;
            }
        }

        if (flag)
            ans = "NO";

        cout << ans << '\n';
    }

    return 0;
}
