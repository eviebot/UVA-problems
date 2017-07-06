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

int n, e, timex, dist[101], visited[101], recent;
vector <vector <pair <int, int>>> graph;
vector <pair <int, int>> temp;
set <pair <int, int>> myset;
set <pair <int, int>>::iterator iter;
void dijkstra()
{

	int j, tt;
	while(myset.size())
	{
		if(recent == e)
			break;

        //cout << recent << " ";
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
    int T, m, i, t, sum, j, u, v;
    cin >> T;
    for(int z = 0; z < T; ++z)
    {
    	cin >> n >> e >> timex >> m;
    	graph.clear();
    	sum = 0;
    	for(i = 0; i <= n; ++i)
    		{graph.pb(temp);}

    	for(i = 0; i < m; ++i)
    	{
    		cin >> u >> v >> t;
    		graph[u].pb(MP(v, t));
    	}
    	for(i = 1; i <= n; ++i)
    	{
    		recent = i;
    		myset.clear();
    		for(j = 1; j <= n; ++j)
    		{
    			visited[j] = 0;
    			dist[j] = 1e6;
    			myset.insert( MP (1e6, j));
    		}
    		myset.erase(myset.find( MP(1e6, i)));
    		visited[i] = 1;
    		dist[i] = 0;
    		dijkstra();

    		if( dist[e] <= timex ){
    			++sum;}
    	}
    	cout << sum << "\n"<< "\n"[z== T-1];
    }
}
