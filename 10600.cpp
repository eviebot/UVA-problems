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

int n, m;
vector <pair <int, pair <int, int>> > kruskal;
vector <int> leader;
vector <vector <int>> edgedata;
vector <bool> visited, edgevisited;

bool BFS()
{
    queue <int> myq;
    int j, temp;

    for(j = 1; j <= n; ++j)
        visited[j] = 0;

    myq.push(1);
    visited[1] = true;

    while(!myq.empty())
    {
        temp = myq.front();
        myq.pop();
        for(j = 1; j <= n; ++j)
        {
            if( edgedata[temp][j] && !visited[j])
            {
                visited[j] = true;
                myq.push(j);
            }
        }
    }

    for(j = 1; j <= n; ++j)
    {
        if( !visited[j])
            return 0;
    }
    return 1;
}
int findleader(int x)
{
    if( x == leader[x])
        return x;

    leader[x] = findleader(leader[x]);
    return leader[x];
}
int findstuffaboutgraph(int root)
{
    int u, v, sum = 0, i;
    for(i = 1; i <= n; ++i){
        leader[i] = 0;edgevisited[i] = 0;}

    for(i =0; i < kruskal.size(); ++i)
    {
        u = kruskal[i].se.fi;
        v = kruskal[i].se.se;
        if( i != root)
        {
            if( !leader[u] )
            {
                if( !leader[v] )
                {
                    leader[u] = v;
                    leader[v] = v;
                }
                else
                {
                    leader[u] = v;
                }
                sum += kruskal[i].fi;
                edgevisited[i] = 1;
            }
            else if( !leader[v])
            {
                leader[v] = u;
                sum += kruskal[i].fi;
                edgevisited[i] = 1;
            }
            else
            {
                if( findleader(u) != findleader(v) )
                {
                    leader[findleader(u)] = findleader(v);
                    sum += kruskal[i].fi;
                    edgevisited[i] = 1;
                }
            }
        }
    }
    return sum;
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    
    
    int T , u, v, c, i, min1, min2;
    cin >> T;


    for(int z =0 ; z < T; ++z)
    {
        leader.clear();
        edgedata.clear();
        visited.clear();
        edgevisited.clear();
        kruskal.clear();

        cin >> n >> m;
        for(i = 0; i <= m; ++i)
            edgevisited.pb(0);
        for(i = 0; i <= n; ++i)
        {
            visited.pb(0);
            leader.pb(0);
        }
        for(i = 0; i <= n; ++i)
        {
            edgedata.pb(leader);
        }
        for(i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            kruskal.pb( MP( c, MP(u, v)) );
            edgedata[u][v] = c;
            edgedata[v][u] = c;
        }
        sort(kruskal.begin(), kruskal.end());

        min1 = findstuffaboutgraph(-1);
        min2 = INT_MAX;



        vector <int> tester;
        for(i = 0; i < m; ++i)
        {
            if( edgevisited[i])
                tester.pb(i);
        }
        for(i = 0; i < tester.size(); ++i)
        {
            u = kruskal[tester[i]].se.fi;
            v = kruskal[tester[i]].se.se;
            c = kruskal[tester[i]].fi;
            edgedata[u][v] = 0;
            edgedata[v][u] = 0;

            if( BFS())
            {
                min2 = min(min2, findstuffaboutgraph(tester[i]));
            }

            edgedata[u][v] = c;
            edgedata[v][u] = c;
        }

        cout << min1 << ' '<< min2 << "\n";
    }
}
