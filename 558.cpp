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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	vector <pair <int, int>> temp;

	cin >>T;
	for(int z = 0; z < T; ++z)
	{
		cin >> n >> m;
		int DP[n][n+1];
		vector <vector <pair <int, int>>> graph;

		for(i =0; i < n; ++i)
		{
			graph.pb(temp);
		}
		for(i = 0; i < m; ++i)
		{
			cin >> u >> v >> t;
			graph[v].pb( MP(u, t));
		}

		for(i = 1; i < n; ++i)
		{
			DP[i][0] = 1e6;
		}
		DP[0][0] = 0;
		for(i = 1;  i <= n; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				DP[j][i] = DP[j][i-1];
				for(k = 0; k < graph[j].size(); ++k)
				{
					if(DP[graph[j][k].fi][i-1] != 1e6)
						DP[j][i] = min(DP[j][i], DP[graph[j][k].fi][i-1] + graph[j][k].se);
				}
			}
		}
		bool flag = true;
	
		for(i = 0; i < n; ++i)
		{
			if( DP[i][n] != DP[i][n-1])
			{
				cout << "possible\n";
				flag = false;
				break;
			}
		}
		if( flag)
			cout << "not possible\n";
	}
}	