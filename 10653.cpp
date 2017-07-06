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

int r, c, src1, src2, dest1, dest2;
vector <vector <bool>> visited;
vector <bool> temp;
vector <vector <int>> dist;
vector <int> temp2;

void BFS()
{
    queue <pair <int, int>> myq;
    int t1, t2;
    visited[src1][src2] = 1;
    dist[src1][src2] = 0;

    myq.push( MP (src1, src2));

    while(true)
    {
        t1 = myq.front().fi;
        t2 = myq.front().se;
        if( t1 == dest1 && t2 == dest2)
        {
            return;
        }
        myq.pop();

        if( ! ( t1-1 < 0 || visited[t1-1][t2]))
        {
            visited[t1-1][t2] = 1;
            dist[t1-1][t2] = dist[t1][t2] +1;
            myq.push( MP (t1-1, t2));
        }
        if( !( t2+1 == c || visited[t1][t2+1]) )
        {
            visited[t1][t2+1] = 1;
            dist[t1][t2+1] = dist[t1][t2] + 1;
            myq.push( MP (t1, t2+1));
        }
        if( ! ( t2-1 < 0 || visited[t1][t2-1]))
        {
            visited[t1][t2-1] = 1;
            dist[t1][t2-1] = dist[t1][t2] +1;
            myq.push( MP (t1, t2-1));
        }
        if( !( t1+1 == r || visited[t1+1][t2]) )
        {
            visited[t1+1][t2] = 1;
            dist[t1+1][t2] = dist[t1][t2] + 1;
            myq.push( MP (t1+1, t2));
        }
    }
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int i, j, u, v, t, t2;
    for(i = 0; i < 1001; ++i)
    {
        temp.pb(0);
        temp2.pb(0);
    }
    for(i = 0; i < 1001; ++i)
    {
        visited.pb(temp);
        dist.pb(temp2);
    }

    while(cin >> r >> c)
    {
        if(!r)
            break;

        for(i = 0; i < r; ++i)
        {
            for(j = 0; j < c; ++j)
            {
                visited[i][j] = 0;
            }
        }
        cin >> t;
        for(i= 0; i < t; ++i)
        {
            cin >> u>> t2;
            for(j = 0; j < t2; ++j)
            {
                cin >> v;
                visited[u][v] = 1;
            }
        }

        cin >> src1 >> src2 >> dest1 >> dest2;
        BFS();
        cout << dist[dest1][dest2]<<"\n";
    }
}
