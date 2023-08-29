#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int parent[100001] = { 0 };

int find_parent(int a) {
    if (parent[a] == a)
        return a;
    else
        return parent[a] = find_parent(parent[a]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int G, P; cin >> G >> P;
    for (int i = 1; i <= G; i++)
        parent[i] = i;

    int ans = 0;
    int t, p;
    for (int i = 0; i < P; i++) {
        cin >> t;
        int p = find_parent(t);
        if (p != 0) {
            parent[p] = find_parent(p - 1);
            ans++;
        }
        else
            break;
    }

    cout << ans << '\n';

    return 0;
}
