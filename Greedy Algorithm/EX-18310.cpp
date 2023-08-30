#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> pos;
int ans = 0, N;
long long min_value = 20000000001;

void find_min_pos(int start, int end) {
    long long left = 0, right = 0;
    int mid = (start + end) / 2;

    if (start > mid || end < mid)
        return;

    for (int i = 0; i < mid; i++)
        left += pos[mid] - pos[i];
    for (int i = mid + 1; i < N; i++)
        right += pos[i] - pos[mid];

    long long t = left + right;
    if (min_value > t) {
        min_value = t;
        ans = pos[mid];
    }

    if (left > right)
        find_min_pos(start, mid - 1);
    else
        find_min_pos(mid + 1, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        pos.push_back(t);
    }

    sort(pos.begin(), pos.end());
    find_min_pos(0, N - 1);

    cout << ans << '\n';

    return 0;
}
