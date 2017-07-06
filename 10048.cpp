// FUCK PRESENTATION ERRORS 
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

int n, s, q;
vector <vector <pair <int, int>>> graph;
vector <vector <vector <pair <int, int>>>> SUPERGRAPH;
vector <pair <int, int>> temp;
vector <bool> visited;
vector <int> dist;
int leader[102];
int minimum_overall, indexsex;
void DFS(int root, int dest, int maxi)
{
    int temp;
    if( visited[root])
        return;

    visited[root] = true;

    if( root == dest ){//cout << root << ' '<< dest << '\n';
        minimum_overall = maxi;return;}

    for(temp = 0; temp < SUPERGRAPH[indexsex][root].size(); ++temp)
    {

        if( !visited[SUPERGRAPH[indexsex][root][temp].fi] )
            DFS(SUPERGRAPH[indexsex][root][temp].fi, dest, max(SUPERGRAPH[indexsex][root][temp].se, maxi));
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int i, j, c1, c2, d, recent, te, v = 1;
    bool flag = false;
    while(cin >> n >> s >> q)
    {
        if( !n)
            break;

        if( flag)
            cout << "\n";
        else
            flag = true;
        graph.clear();
        visited.clear();
        dist.clear();
        SUPERGRAPH.clear();

        map <pair <int, int>, int> mymap;
        map <pair <int, int>, int>::iterator iterate;
        graph.pb(temp);
        dist.pb(0);
        visited.pb(0);
        for( i = 1; i <= n; ++i)
        {
            mymap.insert( MP ( MP(100000, i), 0 ));
            graph.pb(temp);
            dist.pb(100000);
            visited.pb(0);
        }
        for(i =0; i < s; ++i)
        {
            cin >> c1 >> c2 >> d;
            graph[c1].pb(MP (c2, d));
            graph[c2].pb(MP (c1, d));
        }
        for(i = 1; i <= n; ++i)
        {
            if( !visited[i])
            {
                recent = i;
                visited[i] = 1;
                dist[i] = 0;
                iterate = mymap.find( MP(100000, i));

                mymap.erase(iterate);

                vector <vector <pair <int, int>>> temp_graph;
                for(int z = 0; z <= n; ++z)
                    temp_graph.pb(temp);

                while(mymap.size())
                {
                    for(j = 0; j < graph[recent].size(); ++j)
                    {
                        if( !visited[graph[recent][j].fi] )
                        {
                            iterate = mymap.find( MP(dist[graph[recent][j].fi], graph[recent][j].fi));

                            if( graph[recent][j].se < iterate->fi.fi)
                            {
                                //cout <<recent << ' '<< graph[recent][j].fi << " "<< graph[recent][j].se <<"\n";
                                te = graph[recent][j].se;
                                dist[graph[recent][j].fi] = te;
                                mymap.erase(iterate);
                                mymap[MP(graph[recent][j].se, graph[recent][j].fi) ] = recent;
                            }
                        }
                    }

                    iterate = mymap.begin();

                    if( iterate->fi.fi == 100000){
                        break;}

                    recent = iterate->fi.se;
                    te = iterate->se;
                    temp_graph[recent].pb( MP(te, iterate->fi.fi) );
                    temp_graph[te].pb(MP (recent, iterate->fi.fi));
                    visited[recent] = 1;

                    mymap.erase(iterate);
                }
                SUPERGRAPH.pb(temp_graph);
            }

        }
        /*for(i = 0; i < SUPERGRAPH.size(); ++i)
        {
            cout << "level "<< i << "\n";
            for(j = 1; j < SUPERGRAPH[i].size(); ++j)
            {
                for(int k = 0; k < SUPERGRAPH[i][j].size(); ++k)
                {
                    cout  <<j << " = "<< SUPERGRAPH[i][j][k].fi << ' '<< SUPERGRAPH[i][j][k].se << "\n";
                }
            }
        }*/
        cout<< "Case #"<< v++<<"\n";
        for(i = 0; i <q; ++i)
        {
            cin >> c1 >> c2;
            minimum_overall = 0;
            for(j = 0; j < SUPERGRAPH.size(); ++j)
            {
                if( SUPERGRAPH[j][c1].size())
                    indexsex = j;
            }
            for(j = 1; j <= n; ++j)
                visited[j] = 0;
            DFS(c1, c2, 0);
            if( !minimum_overall)
                cout << "no path\n";
            else
                cout << minimum_overall<<"\n";
        }

    }
}
