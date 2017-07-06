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

vector <vector <int>> dfsgraph;
bool deathflags[201], visited[201];
void DFS(int root)
{
	if(visited[root])
	{
		return ;
	}
	deathflags[root] = 0;
	visited[root] = 1;

	for(int j = 0; j < dfsgraph[root].size(); ++j)
	{
		DFS(dfsgraph[root][j]);
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");


	vector <pair <int, int>> temp;
	vector <int> temp2;

	int n, i, j, u, v, r, q, z= 1, k;
	while(scanf("%d", &n) == 1)
	{
		int arr[n+1];
		vector <vector <pair <int , int>>> graph;
		graph.pb(temp);
		dfsgraph.clear();
		dfsgraph.pb(temp2);
		for(i = 1;  i<= n; ++i)
		{
			dfsgraph.pb(temp2);
			graph.pb(temp);
			cin >> arr[i];
		}

		cin >> r;
		for(i = 0; i < r; ++i)
		{
			cin >> u >> v;
			graph[v].pb(MP(u, pow((arr[v]-arr[u]), 3)));
			dfsgraph[u].pb(v);
		}

		int DP[n+1][n+1];
		DP[1][0] = 0;
		for(i = 2; i <= n; ++i)
			DP[i][0] = 1e6;

		for(i = 1; i <= n; ++i)
		{
			for(j = 1; j <= n; ++j)
			{
				DP[j][i] = DP[j][i-1];
				for(k = 0; k < graph[j].size(); ++k)
				{
					if( DP[graph[j][k].fi][i-1] != 1e6)
					{
						DP[j][i] = min(DP[j][i], DP[graph[j][k].fi][i-1] + graph[j][k].se);
					}
				}
			}
		}

		
		cin >> q;
		cout<< "Set #"<< z++<< "\n";
		
		for(i = 1; i <= n; ++i)
			deathflags[i] = 1;

		for(i = 1; i <= n; ++i)
		{
			if(deathflags[i])
			{
				if( DP[i][n] != DP[i][n-1]) {
					for(j = 1; j <= n; ++j){
						visited[j] = 0;
					}
					DFS(i);
				}
				else if( DP[i][n] < 3 || DP[i][n] == 1e6)
					deathflags[i] = false;
			}
		}
		for(i = 0; i < q; ++i)
		{
			cin >> u;
			if( !deathflags[u])
				cout << "?\n";
			else
				cout << DP[u][n-1] << "\n";
		}
	}
}