#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int src, sink, n, t;
int graph[101][101];
bool visited[101];
int configure[101];
int bfs()
{
	int i, temp, j;
	for(i = 1;i <= n; ++i)
	{
		visited[i] = 0;
		configure[i] = -1;
	}

	queue <int> myq;
	myq.push(src);
	visited[src] = 1;
	
	while(!myq.empty())
	{
		temp = myq.front();
		myq.pop();

		for(i =1; i<= n; ++i)
		{
			if( graph[temp][i] && !visited[i])
			{
				visited[i] = 1;
				myq.push(i);
				configure[i] = temp;
			}
		}
	}
	int l = INT_MAX;

	if( configure[sink] == -1)
		return 0;

	temp = sink;
	while(configure[temp] != -1)
	{
		j = configure[temp];
		l = min(l, graph[j][temp]);
		temp = j;
	}
	
	temp = sink;
	while(configure[temp] != -1)
	{
		j = configure[temp];
		graph[j][temp] -= l;
		
		temp = j;
	}
	return l;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, j, u, v, m, z = 1;
	while(cin >> n)
	{
		if( !n)
			break;
		for(i = 1; i <= n; ++i)
		{
			for(j = 1; j <= n; ++j)
			{
				graph[i][j] = 0;
			}
		}

		cin >> src >> sink >> m;
		for(i =0 ; i < m; ++i)
		{
			cin >> u >> v >> t;
			graph[u][v] += t;
			graph[v][u] += t;
		}
		int path = 0;
		while(true)
		{
			t = bfs();
			if( t)
			{
				path += t;
			}
			else
				break;
		}
		cout << "Network "<< z++ << "\n";
		cout << "The bandwidth is "<< path << ".\n\n";
	}

}