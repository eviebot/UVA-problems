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

	
	int n, m, i, j, t, sum, x;
	vector <int> visited, graph, last;
	for(i = 0; i <= 1000000; ++i)
    {
        visited.pb(0);
        last.pb(0);
    }
    for(i = 0; i <= 100000; ++i)
    {
        graph.pb(0);
    }
	while(cin >> n >> m)
	{
		for(i = 0; i <= 1000000; ++i)
		{
            visited[i] = 0;
        }
        for(i = 1; i <= n; ++i)
        {
            graph[i] = 0;
        }
        for(i = 1; i <= n; ++i)
        {
            cin >> t;
            if( visited[t])
            {
                graph[last[t]] = i;
                last[t] = i;
            }
            else
            {
                visited[t] = i;
                last[t] = i;
            }
        }

        for(i = 0; i < m; ++i)
        {
            cin >> t >> j;
            sum = 1;
            x = visited[j];
            if(!visited[j])
            {
                cout << 0 << "\n";
            }
            else if(t == 1)
            {
                cout << x << "\n";
            }
            else
            {
                bool flag = true;
                while(graph[x])
                {
                    ++sum;
                    x = graph[x];
                    if( sum == t)
                    {
                        flag = false;
                        break;
                    }
                }
                if( flag)
                {
                    cout << 0 << "\n";
                }
                else
                {
                    cout << x << "\n";
                }
            }
        }
	}
}
