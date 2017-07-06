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

    fastIO;
    int m, n, i, sum, x, y, z;

    while(cin >> m >> n)
    {
        if(!m)
            break;
        sum = 0;
        vector <vector <pair <int, int>>> graph;
        vector <pair <int, int>> temp;
        vector <bool> visited;
        set <pair <int, int>> prim;
        set <pair <int, int>>::iterator iter;
        vector <int> dist;

        graph.pb(temp);
        visited.pb(1);
        dist.pb(0);
        for(i =1 ; i < m; ++i)
        {
            graph.pb(temp);
            visited.pb(0);
            prim.insert( MP( inf, i ));
            dist.pb(inf);
        }
        for(i =0 ; i < n; ++i)
        {
            cin >> x >> y >> z;
            graph[x].pb(MP(y, z));
            graph[y].pb(MP(x, z));
            sum += z;
        }

        int recent = 0, ssum = 0, te;
        while(prim.size())
        {

            for(i = 0; i <graph[recent].size(); ++i)
            {
                iter = prim.find( MP(dist[graph[recent][i].fi], graph[recent][i].fi));
                if( !visited[graph[recent][i].fi] )
                {
                    if( graph[recent][i].se < iter->fi)
                    {
                        te = graph[recent][i].se;
                        dist[graph[recent][i].fi] = te;
                        prim.erase(iter);
                        prim.insert( MP (te, graph[recent][i].fi));
                    }
                }
            }

            iter = prim.begin();
            recent = iter->se;
            ssum +=  iter->fi;
            visited[recent] = true;
            prim.erase(iter);
        }

        cout << sum-ssum << "\n";
    }
}
