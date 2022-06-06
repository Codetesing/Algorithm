#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	while (1)
	{
		string n;
		cin >> n;
		string temp = n;

		if (n == "0")
			break;

		reverse(n.begin(), n.end());

		if (n == temp)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}