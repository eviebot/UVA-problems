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

    int m, n, i, x, y, z, tt;
    fastIO;
    while(cin >> n >> m)
    {
        if(!n)
            break;
        vector <vector <pair <int, int>>> graph;
        vector <pair <int, int>> temp;
        vector <bool> visited;
        set <pair <int, int>> prim;
        set <pair <int, int>>::iterator iter;
        vector <int> dist, tem;

        vector <vector <int>> edgeL;
        graph.pb(temp);
        visited.pb(1);
        dist.pb(0);

        for(i = 0; i < n; ++i)
        {
            tem.pb(-1);
        }
        edgeL.pb(tem);
        for(i =1 ; i < n; ++i)
        {
            edgeL.pb(tem);
            graph.pb(temp);
            visited.pb(0);
            prim.insert( MP( inf, i ));
            dist.pb(inf);
        }
        for(i =0 ; i < m; ++i)
        {
            cin>> x >> y >> z;
            graph[x].pb(MP(y, z));
            graph[y].pb(MP(x, z));
            edgeL[x][y] = z;
            edgeL[y][x] = z;
        }

        int recent = 0, te;
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
            for(i = 0; i < graph[iter->se].size(); ++i)
            {
                tt = graph[iter->se][i].fi;
                if( visited[tt] && graph[iter->se][i].se == iter->fi )
                {
                    edgeL[tt][iter->se] = -1;
                    edgeL[iter->se][tt] = -1;
                }
            }

            recent = iter->se;
            visited[recent] = true;
            prim.erase(iter);
        }
        vector <int> ans;
        for(i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                if( edgeL[i][j] != -1)
                    ans.pb(edgeL[i][j]);
            }
        }
        if( ans.size())
        {
            sort(ans.begin(), ans.end());
            for(i =0 ; i < ans.size(); ++i)
                cout << ans[i] << " \n"[i==ans.size()-1];
        }
        else
            cout << "forest\n";
    }
}
