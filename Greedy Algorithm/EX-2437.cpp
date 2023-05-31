#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (res + 1 >= arr[i])
            res += arr[i];
        else
            break;
    }

    cout << res + 1 << '\n';

    return 0;
}
