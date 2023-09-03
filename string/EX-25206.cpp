#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n = 20;

    string s, t;
    float score = 0, total = 0, sum = 0, temp = 0;

    for (int i = 0; i < n; i++) {
        cin >> s >> score >> t;
        sum += score;

        temp = -1;
        if (t == "A+")
            temp = 4.5;
        else if (t == "A0")
            temp = 4.0;
        else if (t == "B+")
            temp = 3.5;
        else if (t == "B0")
            temp = 3.0;
        else if (t == "C+")
            temp = 2.5;
        else if (t == "C0")
            temp = 2.0;
        else if (t == "D+")
            temp = 1.5;
        else if (t == "D0")
            temp = 1.0;
        else if (t == "F")
            temp = 0.0;

        if (temp != -1)
            total += (score * temp);
        else
            sum -= score;
    }

    float ans = total / sum;
    printf("%.6f\n", ans);

    return 0;
}
