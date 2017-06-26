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

int n, dist_count[2500];
vector <vector <int>> graph;
vector <int> temp, dist;
vector <bool> visited;

void BFS(int src)
{
    int i, tem;
    for(i = 0; i < n; ++i)
    {
        dist[i] = 0;
        visited[i] =0;
    }
    visited[src] = 1;
    dist[src] =0;
    if( !graph[src].size())
    {
        cout << 0 <<"\n";
        return;
    }

    queue <int> myq;
    myq.push(src);

    while(!myq.empty())
    {
        tem = myq.front();
        myq.pop();

        for(i = 0; i < graph[tem].size(); ++i)
        {
            if( !visited[graph[tem][i]] )
            {
                visited[graph[tem][i]] = 1;
                myq.push(graph[tem][i]);
                dist[graph[tem][i]] = dist[tem] +1;
            }
        }
    }

    for(i = 0; i < n; ++i)
    {
        ++dist_count[dist[i]];
    }
    int maxi = 0, max_index ;
    for(i = 1; i < 2500; ++i)
    {
        if( dist_count[i] > maxi)
        {
            maxi = dist_count[i];
            max_index = i;
        }
    }
    cout << maxi << " "<< max_index << '\n';
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int i, j, u, t;
    while(cin >> n)
    {
        graph.clear();
        dist.clear();
        visited.clear();
        for(i = 1; i <= n; ++i)
        {
            visited.pb(0);
            dist.pb(0);
            cin >> u;

            temp.clear();
            for(j = 0; j < u; ++j)
            {
                cin >> t;
                temp.pb(t);
            }
            graph.pb(temp);
        }

        cin >> u;

        for(i = 0; i < u; ++i)
        {
            for(j = 0; j < 2500; ++j)
                dist_count[j] = 0;
            cin >> t;
            BFS(t);
        }
    }
}
