#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    vector<int> cnt(2, 0);
    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        cnt[t]++;
    }

    t = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    if (t == 0) {
        cout << "Junhee is not cute!" << '\n';
    }
    else {
        cout << "Junhee is cute!" << '\n';
    }

    return 0;
}
