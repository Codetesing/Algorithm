#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long arr[1000001] = { 0 };
long long segTree[4000004] = { 0 };

long long make_segTree(int node, int start, int end) {
    int mid = (start + end) / 2;

    if (start == end)
        return segTree[node] = arr[start];
    else
        return segTree[node] = make_segTree(node * 2, start, mid) + make_segTree(node * 2 + 1, mid + 1, end);
}

void update_segTree(int node, int start, int end, long long target, long long val) {
    if (target < start || end < target)
        return;
    
    segTree[node] += val;
    if (start == end)
        return;

    int mid = (start + end) / 2;
    update_segTree(node * 2, start, mid, target, val);
    update_segTree(node * 2 + 1, mid + 1, end, target, val);
}

long long sum_segTree(int node, int start, int end, long long left, long long right) {
    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
        return segTree[node];

    int mid = (start + end) / 2;
    return sum_segTree(2 * node, start, mid, left, right) + sum_segTree(2 * node + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    make_segTree(1, 0, N - 1);

    long long a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        b--;

        if (a == 1) {
            long long t = c - arr[b];
            arr[b] = c;
            update_segTree(1, 0, N - 1, b, t);
        }
        else {
            long long t = sum_segTree(1, 0, N - 1, b, c - 1);
            cout << t << '\n';
        }
    }

    return 0;
}
