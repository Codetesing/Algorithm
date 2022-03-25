#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string in; cin >> in;
	int alpha[26] = { 0 };

	for (int i = 0; i < in.length(); i++)
		alpha[in[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
	printf("\n");

	return 0;
}
