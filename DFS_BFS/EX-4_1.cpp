#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define NIL -1
#define INFINITY 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

struct node {
	int _weight;
	int _num;
};

class DFS
{
public:
	int* d;
	int* p;
	int* color;
	int v;
	vector<int> topo_sort;

	DFS(int v);
	void INITIALIZE_SINGLE_SOURCE(vector<node>* G, int s);

	void SEARCH(vector<node>* G);
	void DFS_visit(vector<node>* G, int u);
	void PRINT();

	void TOPO_DFS_visit(vector<node>* G, int u);
	void TOPOLOGICAL_SORT(vector<node>* G);
	void TOPO_PRINT();
};

DFS::DFS(int v)
{
	d = new int[v + 1];
	p = new int[v + 1];
	color = new int[v + 1];
}

void DFS::INITIALIZE_SINGLE_SOURCE(vector<node>* G, int s)
{
	for (int i = 1; i <= v; i++)
	{
		d[i] = INFINITY;
		p[i] = NIL;
		color[i] = WHITE;
	}
	d[s] = 0;
}

	//*********** BFS Algorithm *********

void DFS::DFS_visit(vector<node>* G, int u)
{
	color[u] = GRAY;

	for (int v = 0; v < G[u].size(); v++)
		if (color[G[u][v]._num] == WHITE)
		{
			p[G[u][v]._num] = u;
			DFS_visit(G, G[u][v]._num);
		}

	color[u] = BLACK;
}

void DFS::SEARCH(vector<node>* G)
{
	for (int u = 1; u <= v; u++)
		if (color[u] == WHITE)
			DFS_visit(G, u);
}

void DFS::PRINT()
{
	cout << "dfs p[i] : ";
	for (int i = 1; i <= v; i++)
		cout << p[i] << " ";
	cout << endl;
}

	//*********** TOPOLOGICAL_SORT Algorithm *********

void DFS::TOPOLOGICAL_SORT(vector<node>* G)
{
	for (int u = 1; u <= v; u++)
		if (color[u] == WHITE)
			TOPO_DFS_visit(G, u);

	std::reverse(topo_sort.begin(), topo_sort.end());
};

void DFS::TOPO_DFS_visit(vector<node>* G, int u)
{
	color[u] = GRAY;

	for (int v = 0; v < G[u].size(); v++)
		if (color[G[u][v]._num] == WHITE)
		{
			p[G[u][v]._num] = u;
			TOPO_DFS_visit(G, G[u][v]._num);
		}

	color[u] = BLACK;

	topo_sort.push_back(u);
}

void DFS::TOPO_PRINT()
{
	cout << endl;

	cout << "top. sort : ";
	for (int data : topo_sort)
		cout << data << " ";
	cout << endl;
}

	//*********** BFS Algorithm *********

class BFS 
{
public:
	int* d;
	int* p;
	int* color;
	queue<int> q;
	int v;

	BFS(int v);
	void INITIALIZE_SINGLE_SOURCE(vector<node>* G, int s);
	void SEARCH(vector<node>* G);
	void PRINT();
};

BFS::BFS(int v)
{
	d = new int[v + 1];
	p = new int[v + 1];
	color = new int[v + 1];
}

void BFS::INITIALIZE_SINGLE_SOURCE(vector<node>* G, int s)
{
	for (int i = 1; i <= v; i++)
	{
		d[i] = INFINITY;
		p[i] = NIL;
		color[i] = WHITE;
	}

	color[s] = GRAY;
	d[s] = 0;

	q.push(s);
}

void BFS::SEARCH(vector<node>* G)
{
	int u;

	while (!q.empty())
	{
		u = q.front();

		for (int v = 0; v < G[u].size(); v++)
			if (color[G[u][v]._num] == WHITE)
			{
				color[G[u][v]._num] = GRAY;
				d[G[u][v]._num] = d[u] + 1;
				p[G[u][v]._num] = u;
				q.push(G[u][v]._num);
			}

		q.pop();
		color[u] = BLACK;
	}
}

void BFS::PRINT()
{
	cout << "bfs p[i] : ";
	for (int i = 1; i <= v; i++)
		cout << p[i] << " ";
	cout << endl;
}

void PRINT_NODE(vector<node>* G, int v)
{
	for (int i = 1; i <= v; i++)
	{
		cout << i << " ";
		for (int j = 0; j < G[i].size(); j++)
			cout << "(" << G[i][j]._num << " " << G[i][j]._weight << ") ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	ifstream input("input1.txt");
	if (input.fail())
	{
		cerr << "No file" << endl;
		exit(0);
	}

	int v, e;
	int s, d;
	vector<node>* graph;

	input >> v;
	input >> e;

	graph = new vector<node>[v + 1];

	for (int i = 1; i <= e; i++)
	{
		input >> s;
		input >> d;

		node temp;
		temp._num = d;
		temp._weight = 1;

		graph[s].push_back(temp);
	}

	PRINT_NODE(graph, v);

	//*********** DFS Algorithm *********

	DFS dfs(v);
	dfs.v = v;

	dfs.INITIALIZE_SINGLE_SOURCE(graph, 1);
	dfs.SEARCH(graph);
	dfs.PRINT();

	//*********** BFS Algorithm *********

	BFS bfs(v);
	bfs.v = v;

	bfs.INITIALIZE_SINGLE_SOURCE(graph, 1);
	bfs.SEARCH(graph);
	bfs.PRINT();

	//*********** TOPOLOGICAL_SORT Algorithm *********

	DFS dfs_topo(v);
	dfs_topo.v = v;

	dfs_topo.INITIALIZE_SINGLE_SOURCE(graph, 1);
	dfs_topo.TOPOLOGICAL_SORT(graph);
	dfs_topo.TOPO_PRINT();

	input.close();

	return 0;
}