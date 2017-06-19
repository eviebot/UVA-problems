#include <bits/stdc++.h>
using namespace std;

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

int dist[102], tdist[102];
vector <vector <int>> graph;
vector <int> temp;
vector <bool> visited;

void BFS(int root)
{
    visited[root] = 1;
    dist[root] = 0;
    queue <int> myq;
    myq.push(root);
    int temp, j;

    while(!myq.empty())
    {
        temp = myq.front();
        myq.pop();

        for(j = 0; j < graph[temp].size(); ++j)
        {
            if( !visited[graph[temp][j]] )
            {
                visited[graph[temp][j]] = 1;
                dist[graph[temp][j]] = dist[temp] +1;
                myq.push(graph[temp][j]);
            }
        }
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);

    int T, n, r, u, v, i, src, dest;

    cin >> T;
    for(int z = 1; z <=T; ++z)
    {
        cin  >> n >> r;
        graph.clear();
        visited.clear();

        for(i = 0; i < n; ++i)
        {
            graph.pb(temp);
            visited.pb(0);
        }

        for(i = 0; i < r; ++i)
        {
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }

        cin >> src >> dest;

        BFS(src);
        int maximum = 0;
        for(i = 0 ; i < n; ++i)
        {
            visited[i] = 0;
            if(dist[i] > maximum)
                maximum = dist[i];
        }

        for(i = 0; i < n; ++i)
            tdist[i] = dist[i];

        BFS(dest);

        for(i = 0 ; i < n; ++i)
        {
            if( dist[i] + tdist[i] > maximum)
                maximum = dist[i] +tdist[i];
        }

        cout << "Case "<< z<< ": "<< maximum << "\n";
    }
}
