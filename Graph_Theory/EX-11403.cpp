#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100
#define INF 1000000

int N;
int d[MAX][MAX];
int map[MAX][MAX];


void FLOYD(int index) {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (d[i][index] + d[index][j] < d[i][j])
				d[i][j] = d[i][index] + d[index][j];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			d[i][j] = INF;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				d[i][j] = 1;
		}

	for (int i = 0; i < N; i++)
		FLOYD(i);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (d[i][j] != INF)
				cout << 1 << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}

	return 0;
}