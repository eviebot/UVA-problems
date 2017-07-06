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

vector <vector <int>> graph;
vector <int> temp;
bool visited[52];
int dist[52];
int n, r;
string s1, s2;

int BFS_2(int root)
{
    int temp, j;
    for(j = 0; j <= n; ++j)
    {
        visited[j] = 0;
    }
    dist[root] = 0;
    visited[root] = 1;
    queue <int> myq;

    myq.push(root);

    while(!myq.empty())
    {
        temp = myq.front();
        myq.pop();
        for(j = 0; j < graph[temp].size(); ++j)
        {
            if( !visited[graph[temp][j]] )
            {
                dist[graph[temp][j]] = dist[temp] +1;
                visited[graph[temp][j]] =1;
                myq.push(graph[temp][j]);
            }
        }
    }
    int maxi = 0;
    for(j = 1; j <= n; ++j)
    {
        if( dist[j] > maxi)
            maxi = dist[j];
    }
    return maxi;
}
bool BFS_1(int root)
{
    queue <int> myq;
    visited[root] = true;
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
                visited[graph[temp][j]] =1;
                myq.push(graph[temp][j]);
            }
        }
    }

    for(j = 1; j <= n; ++j)
    {
        if( !visited[j])
            return false;
    }
    return true;
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int i, j, k, z = 1, bf;
    while(cin >> n >> r)
    {
        if( !n)
            break;

        unordered_map <string, int> mymap;
        int c = 1;
        graph.clear();
        for(i = 0; i <= n; ++i)
        {
            graph.pb(temp);
            visited[i] = 0;
        }

        for(i = 0; i < r; ++i)
        {
            cin >>s1 >> s2;
            if( mymap.find(s1) == mymap.end())
                mymap.insert( MP (s1, c++));
            if( mymap.find(s2) == mymap.end())
                mymap.insert( MP(s2, c++));

            j = mymap.find(s2)->se;
            k = mymap.find(s1)->se;
            graph[j].pb(k);
            graph[k].pb(j);
        }

        cout << "Network "<< z++;
        if( BFS_1(1))
        {
            int maximum = 0;
            for(i = 1; i <= n; ++i)
            {
                bf = BFS_2(i);
                if( bf > maximum)
                    maximum = bf;
            }
            cout << ": "<< maximum << "\n\n";
        }
        else
        {
            cout << ": DISCONNECTED\n\n";
        }
    }
}
