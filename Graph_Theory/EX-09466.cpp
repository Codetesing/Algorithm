#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 100001

using namespace std;

int parent[MAX] = { 0 };
bool visited[MAX] = { false };
bool cycle[MAX] = { false };
int ans = 0;

void DFS(int p) {
    visited[p] = true;
    int next = parent[p];

    if (!visited[next]) DFS(next);

    else if (!cycle[next]) {
        for (int i = next; i != p; i = parent[i]) {
            ans++;
        }
        ans++;
    }

    cycle[p] = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T; cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n; cin >> n;
        ans = 0;

        for (int i = 1; i <= n; i++) {
            cin >> parent[i];
            visited[i] = false;
            cycle[i] = false;
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                DFS(i);
        }

        cout << n - ans << '\n';
    }

    return 0;
}
