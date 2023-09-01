#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> ship(N);
    for (int i = 0; i < N; i++)
        cin >> ship[i];
    int M;
    cin >> M;
    vector<int> box(M);
    for (int i = 0; i < M; i++)
        cin >> box[i];

    sort(ship.begin(), ship.end(), cmp);
    sort(box.begin(), box.end(), cmp);

    int ans = 0;
    if (ship[0] < box[0])
        ans = -1;
    else {
        while (!box.empty()) {
            ans++;
            for (int i = 0; i < ship.size(); i++) {
                for (int j = 0; j < box.size(); j++) {
                    if (ship[i] >= box[j]) {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
