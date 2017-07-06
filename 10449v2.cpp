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

	int n, i, j, u, v, r, q, z= 1, k;
	while(scanf("%d", &n) == 1)
	{
		int arr[n+1];
		vector <vector <pair <int , int>>> graph;
		graph.pb(temp);
		for(i = 1;  i<= n; ++i)
		{
			graph.pb(temp);
			cin >> arr[i];
		}

		cin >> r;
		for(i = 0; i < r; ++i)
		{
			cin >> u >> v;
			graph[v].pb(MP(u, pow((arr[v]-arr[u]), 3)));
		}

		int DP[2*n+1][n+1];
		DP[1][0] = 0;
		for(i = 2; i <= n; ++i)
			DP[i][0] = 1e6;

		for(i = 1; i <= 2*n; ++i)
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

		bool deathflags[n+1];
		cin >> q;
		cout << "Set #"<< z++<< "\n";
		
		for(i = 1; i <= n; ++i)
			deathflags[i] = 1;
		for(i = 1; i <= n; ++i)
		{
			if( DP[i][2*n] < 3 || DP[i][2*n] == 1e6)
					deathflags[i] = false;
		}
		for(i = 0; i < q; ++i)
		{
			cin >> u;
			if( !deathflags[u])
				cout<< "?\n";
			else
				cout << DP[u][2*n] << "\n";
		}
	}
}