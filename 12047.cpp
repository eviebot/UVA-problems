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
#define pii pair <int, int>
#define pll pair <long long>
#define pipii pair <int, pii>
#define plpll pair <long, pll>

typedef long long int lli;

ofstream outfile;
ifstream infile;

int n, m , s, ttt, p, recent;
vector <pair <int, int>> maxi;
vector <vector <pair <int, int>>> graph;
vector <pair <int, int>> temp;

void dijkstra()
{
	int i, j, t, val;
	set <pii> myset;
	set <pii>::iterator iter;
	for( i = 1;  i<= n; ++i)
	{
		if( i!= s){
			myset.insert (MP(-1, i));
		}
	}

	while(true)
	{
	    cout << recent << "\n";
		for(j = 0; j < graph[recent].size(); ++j)
		{
			t = graph[recent][j].fi;
			iter = myset.find( MP (maxi[t].fi, t ));
            val = max(graph[recent][j].se, maxi[recent].fi);


            if( iter == myset.end())
            {
                if( maxi[recent].se + graph[recent][j].se <= p && ( val > maxi[t].fi) )
                {
                    maxi[t].fi = val;
                    maxi[t].se = maxi[recent].se + graph[recent][j].se;
                    myset.insert( MP (maxi[t].fi, t));
                }
            }
			else if(maxi[recent].se + graph[recent][j].se <= p && ( val > iter->fi ))
			{
			    //cout << recent << " "<< t << " "<< graph[recent][j].se << " "<< iter->fi << "\n";
				maxi[t].fi = val;
				maxi[t].se = maxi[recent].se + graph[recent][j].se;
				myset.erase(iter);
				myset.insert(MP (maxi[t].fi, t));
			}
		}
		if( !myset.size())
            break;

		iter = myset.end();
		--iter;
		if( iter->fi == -1)
			break;

		recent = iter->se;
		myset.erase(iter);
//		cout << myset.size() << " "<< recent << '\n';
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int i, t, u, v;
	for(i = 0; i <= 10000; ++i)
	{
		maxi.pb( MP(-1, 0));
	}

	int T;
	infile >> T;
	for(int z = 0; z < T; ++z)
	{
		infile >> n >> m >> s >> ttt >> p;
		graph.clear();
		for(i = 0; i <= n; ++i)
		{
			graph.pb(temp);
			maxi[i].fi = -1;
			maxi[i].se = 0;
		}

		for(i = 0; i < m; ++i)
		{
			infile >> u >> v >> t;
			graph[u].pb( MP(v, t));
		}

		recent = s;
		maxi[s].fi = 0;

		dijkstra();
        cout << maxi[ttt].fi << "\n";
	}
}
