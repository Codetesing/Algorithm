#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define MAX 10000

using namespace std;

char command[] = { 'D', 'S', 'L', 'R' };

pair<int, string> work(pair<int, string> c, char com) {
    string s = c.second + com;
    int t = c.first;

    if (com == 'D') {
        t = (t * 2) % MAX;
    }
    else if (com == 'S') {
        if (t == 0) {
            t = 9999;
        }
        else {
            t -= 1;
        }
    }
    else if (com == 'L') {
        t = ((t % 1000) * 10) + (t / 1000);
    }
    else if (com == 'R') {
        t = ((t % 10) * 1000) + (t / 10);
    }

    return { t, s };
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int A, B; cin >> A >> B;
        bool visited[MAX] = { false };
        queue<pair<int, string>> q;
        q.push({ A, "" });
        visited[A] = true;

        string ans = "";
        while (!q.empty()) {
            pair<int, string> cur = q.front();
            q.pop();
            bool flag = false;

            for (int i = 0; i < 4; i++) {
                pair<int, string> next = work(cur, command[i]);
                if (next.first == B) {
                    flag = true;
                    ans = next.second;
                    break;
                }

                if (!visited[next.first]) {
                    q.push(next);
                    visited[next.first] = true;
                }
            }

            if (flag)
                break;
        }

        cout << ans << '\n';
    }

    return 0;
}
