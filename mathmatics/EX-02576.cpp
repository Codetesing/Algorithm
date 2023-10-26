#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int temp, sum = 0;
    for (int i = 0; i < 7; i++) {
        cin >> temp;
        if (temp % 2 == 1) {
            v.push_back(temp);
            sum += temp;
        }
    }

    if (v.empty()) {
        cout << -1 << '\n';
    }
    else {
        cout << sum << '\n';
        cout << *min_element(v.begin(), v.end()) << '\n';
    }


    return 0;
}
