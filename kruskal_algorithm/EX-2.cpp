#include <iostream>
#include <fstream>

using namespace std;

class Sets
{
public:
	Sets(int sz);
	void weightedUnion(int i, int j);
	int CollapsingFind(int i);

private:
	int* parent;
	int n;
};

Sets::Sets(int sz)
{
	n = sz;
	parent = new int[sz];
	for (int i = 1; i <= n; i++)
		parent[i] = -1;
}

void Sets:: weightedUnion(int i, int j)
{
	int temp = parent[i] + parent[j];

	if (parent[i] > parent[j])
	{
		parent[i] = j;
		parent[j] = temp;
	}

	else
	{
		parent[j] = i;
		parent[i] = temp;
	}
}

int Sets::CollapsingFind(int i)
{
	int r;

	for (r = i; parent[r] >= 0; r = parent[r]);

	while (i != r)
	{
		int s = parent[i];
		parent[i] = r;
		i = s;
	}

	return r;
}

int main()
{
	ifstream input("input.txt");
	if (input.fail())
	{
		cerr << "No file" << endl;
		exit(0);
	}

	int n, m;

	input >> n;
	input >> m;

	Sets sets(n);

	for (int k = 0; k < m; k++)
	{
		int i, j, w, p, q;

		input >> i;
		input >> j;
		input >> w;

		p = sets.CollapsingFind(i);
		q = sets.CollapsingFind(j);

		if (p != q)
		{
			sets.weightedUnion(p, q);
			cout << i << " " << j << " " << w << endl;
		}
	}

	input.close();

	return 0;
}