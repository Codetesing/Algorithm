#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int to_min(int a) {
    string t = to_string(a);

    for (int i = 0; i < t.size(); i++)
        if (t[i] == '6')
            t[i] = '5';

    return stoi(t);
}

int to_max(int a) {
    string t = to_string(a);

    for (int i = 0; i < t.size(); i++)
        if (t[i] == '5')
            t[i] = '6';

    return stoi(t);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, B; cin >> A >> B;

    cout << to_min(A) + to_min(B) << ' ' << to_max(A) + to_max(B) << '\n';

    return 0;
}
