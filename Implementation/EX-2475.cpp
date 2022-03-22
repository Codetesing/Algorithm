#include <iostream>

using namespace std;

int main()
{
	int N = 5;
	int temp, sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sum += temp * temp;
	}

	cout << sum % 10 << endl;

	return 0;
}