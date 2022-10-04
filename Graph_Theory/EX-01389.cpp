#include <iostream>

using namespace std;

#define MAX 101
#define INF 987654321

int N;
int map[MAX][MAX];

void FLOYD (int ind) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] > map[i][ind] + map[ind][j])
				map[i][j] = map[i][ind] + map[ind][j];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = INF;

	int s, e;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		map[s][e] = 1;
		map[e][s] = 1;
	}

	for (int i = 1; i <= N; i++)
		FLOYD(i);

	int out = 0, min_val = INF;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
			sum += map[i][j];
		if (sum < min_val)
		{
			min_val = sum;
			out = i;
		}
	}

	cout << out << '\n';

	return 0;
}