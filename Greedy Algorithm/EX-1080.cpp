#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> mat1;
vector<string> mat2;
int N, M;

void trans(int r, int c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat1[r + i][c + j] == '0')
                mat1[r + i][c + j] = '1';
            else
                mat1[r + i][c + j] = '0';
        }
    }
}

bool IS_SAME() {
    for (int i = 0; i < N; i++)
        if (mat1[i] != mat2[i])
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    string t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        mat1.push_back(t);
    }
    for (int i = 0; i < N; i++) {
        cin >> t;
        mat2.push_back(t);
    }

    int res = 0;
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                trans(i, j);
                res++;
            }
        }
    }

    if (!IS_SAME())
        res = -1;

    cout << res << '\n';

    return 0;
}
