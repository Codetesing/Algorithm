#include <iostream>
#include <fstream>

using namespace std;

#define INFINITY 100
#define NULL -1

class RACE
{
public:
	int* T;
	int* P;
	int* d;
	int* t;
	int M, n, D;
	int num_stations;

	void INPUT();
	void INITIALIZE(int n);
	void SEARCH();
	void SEARCH_NUMS(int k);
	void PRINT();
	void PRINT_STATIONS(int k);
};

void RACE::INITIALIZE(int n)
{
	T = new int[n + 2];
	P = new int[n + 2];
	d = new int[n + 2];
	t = new int[n + 2];

	d[n + 1] = INFINITY;
	t[n + 1] = 0;
	num_stations = 0;

	T[0] = 0;
	P[0] = NULL;

	for (int i = 1; i <= n + 1; i++)
	{
		T[i] = INFINITY;
		P[i] = NULL;
	}
}

void RACE::INPUT()
{
	ifstream input("input2.txt");

	if (input.fail())
	{
		cerr << "No file" << endl;
		exit(0);
	}

	input >> M;
	input >> n;

	INITIALIZE(n);

	for (int i = 0; i <= n; i++)
		input >> d[i];

	for (int i = 1; i <= n; i++)
		input >> t[i];

	input.close();
}

void RACE::SEARCH_NUMS(int k)
{
	if (P[k] != -1)
	{
		SEARCH_NUMS(P[k]);
		num_stations++;
	}
}

void RACE::SEARCH()
{
	for (int i = 0; i <= n; i++)
	{
		int j = i + 1;
		int D = d[i];

		while ((j <= n + 1) && (D <= M))
		{
			if (T[j] > T[i] + t[j])
			{
				T[j] = T[i] + t[j];
				P[j] = i;
			}

			D += d[j];
			j++;
		}
	}

	SEARCH_NUMS(P[n + 1]);
}

void RACE::PRINT()
{
	cout << T[n + 1] << endl;

	cout << num_stations << endl;

	PRINT_STATIONS(P[n + 1]);
	
	//cout << endl;
	//cout << num_stations << endl;
}

void RACE::PRINT_STATIONS(int k)
{
	if (P[k] != -1)
	{
		//num_stations++;
		PRINT_STATIONS(P[k]);
		cout << k << ' ';
	}
}

int main()
{
	RACE race;
	
	race.INPUT();
	race.SEARCH();
	race.PRINT();
}