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

int M, W;
int graph[102][102];
bool visited[102];
int configure[102];

int BFS()
{
	int path = INT_MAX, i, t, p;
	bool flag = false;

	queue <int> myq;
	myq.push(1);

	for(i = 1; i <= 100; ++i)
	{
		visited[i] = 0;
		configure[i] = -1;
	}
	visited[1] = 1;

	while(!myq.empty())
	{
		t = myq.front();
		myq.pop();

		if( t == M)
		{
			flag = true;
			break;
		}
		for(i = 1; i <= 100; ++i)
		{
			if( !visited[i] && graph[t][i] )
			{
				configure[i] = t;
				myq.push(i);
				visited[i] = 1;
			}
		}
	}

	if( !flag)
		return 0;

	t = M;

	while( configure[t] != -1 )
	{
		p = configure[t];
		path = min(path, graph[p][t]);
		t = p;
	}

	t= M;

	while(configure[t] != -1)
	{
		p = configure[t];
		graph[p][t] -= path;
		graph[t][p] += path;
		t = p;
	}
	return path;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, t, u, v, c, sum, j;
	while(cin >> M >> W)
	{
		if( !M)
			break;

		for(i = 1; i <= 100; ++i)
		{
			for(j = 1; j <= 100; ++j)
			{
				graph[i][j] = 0;
			}
		}
		graph[1][51] = INT_MAX;
		graph[M][M+50] = INT_MAX;

		for(i = 1; i < M-1; ++i)
		{
			cin >> t >> c;
			graph[t][50+t] = c;
			graph[50+t][t] = 0;
		}

		for(i = 0; i < W; ++i)
		{
			cin >> u >> v >> c;
			graph[u+50][v] = c;
			graph[v][u+50] = 0;
			graph[v+50][u] = c;
			graph[u][v+50] = 0;
		}

		sum = 0;
		while(true)
		{
			t = BFS();
			if( t)
				sum += t;
			else
				break;
		}
		cout << sum << "\n";
	}
}