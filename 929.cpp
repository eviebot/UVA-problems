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

int n, m, r, c ,srcr, srcc, directions[4][2];
vector <vector <bool>> visited;
vector <vector <int>> dist, edgeL;
vector <int> tt1;
vector <bool> tt2;
pair <int, int> recent;

void dijkstra()
{
	set <pair <int, pair <int, int>>> myset;
	set <pair <int, pair <int, int>>>::iterator iter;
	int i, t;

	while(1)
	{
	    if( recent.fi == n && recent.se == m){
			cout << dist[n][m] << "\n";
			break;
		}
		srcr = recent.fi;
		srcc = recent.se;

		for(i = 0; i < 4; ++i)
		{
			r = srcr + directions[i][0];
			c = srcc + directions[i][1];
			if( r && r != n+1 && c && c != m+1 && !visited[r][c])
			{
				iter = myset.find(MP (dist[r][c], MP(r, c)));
				t = dist[srcr][srcc] + edgeL[r][c];
				if( dist[r][c] == INT_MAX)
				{
					dist[r][c] = t;
					myset.insert( MP (t, MP(r, c)));
				}

				else if( t < dist[r][c])
				{
					dist[r][c] = t;
					myset.erase(iter);
					myset.insert( MP (t, MP(r, c)));
				}
			}
		}

		iter = myset.begin();
		visited[iter->se.fi][iter->se.se] = 1;
		recent = {iter->se.fi, iter->se.se};
		myset.erase(iter);
	}
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;

    directions[0][0] = 1;
    directions[0][1] = 0;
    directions[1][0] = -1;
    directions[1][1] = 0;
    directions[2][0] = 0;
    directions[2][1] = 1;
    directions[3][0] = 0;
    directions[3][1] = -1;
    int T, i, j, t;
    cin>> T;
    for(i = 0; i <= 1000; ++i)
    {
        tt1.pb(0);
        tt2.pb(0);
    }
    for(i = 0; i <= 1000; ++i)
    {
        edgeL.pb(tt1);
        dist.pb(tt1);
        visited.pb(tt2);
    }
    for(int z = 0; z < T; ++z)
    {
    	cin >> n >> m;

	    for(i = 1; i <= n; ++i)
	    {
	    	for(j = 1; j <= m ; ++j)
	    	{
	    		cin >> t;
	    		edgeL[i][j] = t;
	    		dist[i][j] = INT_MAX;
	    		visited[i][j] = 0;
	    	}
	    }
	    dist[1][1] = edgeL[1][1];
	    visited[1][1] = 1;
	    //myset.erase(myset.find(MP(INT_MAX, MP(1, 1))));
	    recent = {1, 1};
	    dijkstra();
	}
}
