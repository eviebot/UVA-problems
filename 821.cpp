#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

typedef long long int lli;
ofstream outfile;
ifstream infile;

vector <vector <int>> graph;
vector <int> temp, matching(101);
vector <bool> visited(101);
int dist[101][101];

void BFS(int index)
{
    queue <int> myq;
    myq.push(index);
    visited[index] = 1;
    dist[index][index] = 0;
    int temp;
    while(!myq.empty())
    {
        temp = myq.front();
        myq.pop();
        for(int j = 0; j < graph[temp].size(); ++j)
        {
            if( !visited[graph[temp][j]] )
            {
                visited[graph[temp][j]] = 1;
                myq.push(graph[temp][j]);
                dist[index][graph[temp][j]] = dist[index][temp] + 1;
            }
        }
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    //ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);

    cout << fixed << setprecision(3);
    int u, v, i, j, z =1;
    lli sum ;
    while(cin >> u >> v)
    {
        if( !u)
            break;
        int c = 0;
        graph.clear();
        for(i = 1; i < 101; ++i)
        {
            for(j = 1; j <= 100; ++j)
                dist[i][j] = 0;
            graph.pb(temp);
            matching[i] = 0;
        }

        matching[u] = ++c;
        matching[v] = ++c;

        graph[matching[u]].pb(matching[v]);
        while(cin >> u >> v)
        {
            if( !u)
                break;

            if( !matching[u])
                matching[u] = ++c;
            if( !matching[v])
                matching[v] = ++c;

            graph[matching[u]].pb(matching[v]);
        }

        for(i = 1; i <= c; ++i)
        {
            for(j = 1; j <= c; ++j)
                visited[j] = 0;

            BFS(i);
        }
        sum = 0;
        for(i = 1; i <= c; ++i)
        {
            for(j = 1; j <= c; ++j)
            {
                sum += dist[i][j];
                //cout << i << " dist to "<< j << " = "<< dist[i][j] << "\n";
            }
        }
        cout << "Case "<< z++<<": average length between pages = "<< double(sum)/ (c * (c-1)) << " clicks\n";

    }
}
