#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321
#define MAX 101

int N, M;
int d[MAX][MAX];

void FLOYD(int ind) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			d[i][j] = min(d[i][j], d[i][ind] + d[ind][j]);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			d[i][j] = INF;

	int x, y, w;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> w;
		d[x][y] = min(d[x][y], w);
	}

	for (int i = 1; i <= N; i++)
		d[i][i] = 0;

	for (int i = 1; i <= N; i++)
		FLOYD(i);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (d[i][j] == INF)
				d[i][j] = 0;
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}