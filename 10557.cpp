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

int energy[101];
bool deathflags[101], visited[101];
vector <vector <int>> dfsgraph;
vector <pair <int, int>> temp1;
vector <int> temp2;
int n;

void DFS(int root)
{
	if( visited[root])
		return;
	visited[root] = 1;
	deathflags[root] = 1;
	for(int j = 0; j < dfsgraph[root].size(); ++j)
	{
		DFS(dfsgraph[root][j]);
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, j, n_rooms, v, k;
	while(cin >> n)
	{
		if(n == -1)
			break;
		dfsgraph.clear();
		vector <vector <pair <int, int>>> graph;
		
		for(i = 0; i <= n; ++i)
		{
			graph.pb(temp1);
			dfsgraph.pb(temp2);
		}
		for(i =1; i <= n; ++i)
		{
			cin >> energy[i]>> n_rooms;

			for(j = 0; j < n_rooms; ++j)
			{
				cin >> v;
				graph[v].pb(MP(i, 0));
				dfsgraph[i].pb(v);
			}
		}

		for(i = 1; i <= n; ++i)
		{
			for(j = 0; j < graph[i].size() ; ++j)
			{
				graph[i][j].se = energy[i];
			}
		}

		int DP[n+1][n+1];

		DP[1][0] = 100;
		for(i = 2; i <= n; ++i)
		{
			DP[i][0] = -1e6;
		}

		for(i = 1; i <= n; ++i)
		{
			for(j= 1; j<= n; ++j)
			{
				DP[j][i] = DP[j][i-1];
				for(k = 0; k < graph[j].size(); ++k)
				{
					if(DP[graph[j][k].fi][i-1] != -1e6)
					{
						DP[j][i] = max(DP[graph[j][k].fi][i-1] + graph[j][k].se, DP[j][i]);
						if( DP[j][i] <= 0)
							DP[j][i] = -1e6;
					}
				}
			}
		}
		/*for(i = 0; i <= n; ++i)
		{
			for(j= 1; j <= n; ++j)
			{
				cout << DP[j][i] << " ";
			}
			cout << "\n";
		}*/
		for(i = 1; i <= n; ++i)
		{
			deathflags[i]= 0;
		}

		for(i = 1; i <= n; ++i)
		{
			if(!deathflags[i])
			{
				if( DP[i][n] != DP[i][n-1] )
				{
					for(j = 1; j <= n; ++j)
						visited[j] = 0;
					DFS(i);
				}
				else if(DP[i][n-1] > 0)
				{
					deathflags[i] = 1;
				}
			}
		}

		if( deathflags[n])
			cout << "winnable\n";
		else
			cout << "hopeless\n";
	}
}	