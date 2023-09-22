#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define MAX 8001

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    vector<int> v(N);
    int arr[MAX] = { 0 };
    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        arr[v[i] + 4000]++;
        sum += v[i];
    }

    sort(v.begin(), v.end());

    int ans1 = round((double)sum / N);
    int ans2 = v[(N - 1) / 2];
    int ans3 = 0;
    for (int i = 0; i < MAX; i++) {
        if (arr[i] > arr[ans3]) {
            ans3 = i;
        }
    }

    for (int i = ans3 + 1; i < MAX; i++) {
        if (arr[i] == arr[ans3]) {
            ans3 = i;
            break;
        }
    }
    ans3 -= 4000;

    int ans4 = v[N - 1] - v[0];

    cout << ans1 << '\n';
    cout << ans2 << '\n';
    cout << ans3 << '\n';
    cout << ans4 << '\n';

    return 0;
}
