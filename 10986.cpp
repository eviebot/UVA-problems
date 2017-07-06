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

int n, m, s, t, recent;
vector <vector <pair <int, int>>> graph;
vector <pair <int, int>> temp;
set <pair <int, int>> myset;
set <pair <int, int>>::iterator iter;
vector <int> dist;
vector <bool> visited;
void dijkstra()
{

	int j, tt;
	while(myset.size())
	{
		if(recent == t)
			break;

		for(j= 0; j < graph[recent].size(); ++j)
		{
			if( !visited[graph[recent][j].fi])
			{
				tt = dist[recent] + graph[recent][j].se;
				iter = myset.find( MP (dist[graph[recent][j].fi], graph[recent][j].fi));
				if ( tt < dist[graph[recent][j].fi])
				{
					dist[graph[recent][j].fi] = tt;
					myset.erase(iter);
					myset.insert( MP (tt, graph[recent][j].fi ));
				}
			}
		}
		//cout << "checker\n";
		iter = myset.begin();
		recent = iter->se;
		myset.erase(iter);
		visited[recent] = 1;
	}
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int cases, i, u, v, latency;
    cin >> cases;

    for(i = 0; i < 20002; ++i)
    {
        dist.pb(0);
        visited.pb(0);
    }
    for(int z = 1; z <= cases; ++z)
    {
        graph.clear();
        myset.clear();
        cin>> n >> m >> s >> t;

        for(i = 0; i <n;++i)
        {
            myset.insert( MP (1e8, i));
            graph.pb(temp);
            dist[i] = 1e8;
            visited[i] = 0;
        }

        for(i = 0; i < m; ++i)
        {
            cin >> u >> v >> latency;
            graph[u].pb( MP (v, latency));
            graph[v].pb( MP (u, latency));
        }

        recent = s;
        dist[s] = 0;
        visited[s] = 1;
        myset.erase( MP (1e8, s));
        dijkstra();
        cout << "Case #"<< z << ": ";
        if( dist[t] == 1e8)
            cout << "unreachable\n";
        else
            cout << dist[t] << "\n";
    }
}
