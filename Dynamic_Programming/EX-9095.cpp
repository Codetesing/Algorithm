#include <iostream>

using namespace std;

int N_SUM(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	else
		return N_SUM(n - 1) + N_SUM(n - 2) + N_SUM(n - 3);
}

int main()
{
	int T; cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;

		cout << N_SUM(n) << endl;
	}

	return 0;
}