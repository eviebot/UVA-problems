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

int n_lifts, k, time_lifts[6], liftno, floorno, recent;
vector <vector <int>> lift2floor, floor2lift;
vector <int> dist, temp;
vector <bool> visited;
set <pair <int, int>> myset;
set <pair <int, int>>::iterator iter;

void dijkstra()
{
	int i, j, t;
	while(myset.size())
	{
		for(i = 0; i < floor2lift[recent].size(); ++i)
		{
			liftno = floor2lift[recent][i];
			for(j = 0; j < lift2floor[liftno].size(); ++j)
			{
				floorno = lift2floor[liftno][j];
				if( !visited[floorno])
				{
					iter = myset.find( MP (dist[floorno], floorno));
					t = dist[recent] + 60 + time_lifts[liftno] * abs(floorno-recent);
					if( t < iter->fi)
					{
						dist[floorno] = t;
						myset.erase(iter);
						myset.insert( MP (t, floorno));
					}
				}
			}
		}

		iter = myset.begin();
		if ( iter->fi == INT_MAX)
			break;
		recent = iter->se;
		visited[recent] = 1;
		myset.erase(iter);
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int i, t, j;
	char c;
	for(i = 0; i < 100; ++i)
	{
		visited.pb(0);
		dist.pb(0);
	}
	while(cin >> n_lifts >> k)
	{
		lift2floor.clear();
		floor2lift.clear();
		myset.clear();
		for(i = 0; i <= n_lifts; ++i)
		{
			lift2floor.pb(temp);
		}
		for(i = 0; i < 100; ++i)
		{
			floor2lift.pb(temp);
			visited[i] = 0;
			dist[i] = INT_MAX;
			myset.insert( MP (INT_MAX, i));
		}

		for(i = 1; i <= n_lifts; ++i)
		{
			cin >> time_lifts[i];
		}
		for(i = 1; i <= n_lifts; ++i)
		{
			while(true)
			{
				scanf("%d%c", &t, &c);
				lift2floor[i].pb(t);
				floor2lift[t].pb(i);
				if( c == '\n')
					break;
			}
		}

		/*for(i = 0; i <=99 ; ++i)
		{
			cout << i << " = ";
			for(j = 0; j <  floor2lift[i].size(); ++j)
			{
				cout << floor2lift[i][j] << ' ';
			}
			cout << '\n';
		}*/

		myset.erase(myset.find(MP(INT_MAX, 0)));
		visited[0] = 1;
		dist[0] = 0;

		for(i = 0; i < floor2lift[0].size(); ++i)
		{
		    liftno = floor2lift[0][i];
			for(j = 0; j < lift2floor[liftno].size(); ++j)
			{
			    floorno = lift2floor[liftno][j];
			    if( floorno)
                {
                    iter = myset.find(MP(dist[floorno], floorno));
                    t = time_lifts[liftno] * floorno;
                    if( t < iter->fi )
                    {
                        myset.erase(iter);
                        myset.insert(MP (t, floorno));
                        dist[floorno] = t;
                    }
                }
			}
		}
		recent = 0;
		dijkstra();
		/*for(i = 0; i < 100; ++i)
		{
			cout << "time to "<< i << " = "<< dist[i] << '\n';
		}*/

		if( dist[k] == INT_MAX)
            cout << "IMPOSSIBLE\n";
        else
            cout << dist[k] << "\n";

	}
}
