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

int n, m, c1, c2;
string s;

vector <vector <int>> graph;
vector <int> temp1;
bool visited[30];

int doit()
{
	bool flag = false, flag2 = false;
	vector <int> candi;
	int i, j, sum;
	for(i = 1;i <= n; ++i)
	{
		if( !visited[i])
		{
			sum = 0;
			for(j = 0; j < graph[i].size(); ++j)
			{
				if( visited[graph[i][j]])
					++sum;
			}
			if( sum > 2)
			{
				candi.pb(i);
				flag = true;
			}
		}
	}
	for(i = 0; i < candi.size(); ++i)
    {
        visited[candi[i]] = 1;
    }
	for(i = 1; i <= n; ++i)
	{
		if( !visited[i])
		{
			flag2 = true;
			break;
		}
	}
	if( !flag2)
		return 0;

	if( !flag )
		return -1;

    return 69;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
    
    fastIO;
	int i, t;
	while(cin >> n>> m)
	{
	    unordered_map <char, int> mymap;
	    int num = 3;
		graph.clear();
		for(i = 0; i <= n; ++i)
		{
			visited[i] = 0;
			graph.pb(temp1);
		}
		cin >> s;
		mymap[s[0]] = 1;
		mymap[s[1]] = 2;
		mymap[s[2]] = 3;
		visited[1] = 1;
		visited[2] = 1;
		visited[3] = 1;

		for(i = 0; i < m; ++i)
		{
			cin >> s;
			if( mymap.find(s[0]) == mymap.end())
            {
                mymap[s[0]] = ++num;
            }
            if( mymap.find(s[1]) == mymap.end())
            {
                mymap[s[1]] = ++num;
            }
            c1 = mymap[s[0]];
            c2 = mymap[s[1]];
			graph[c1].pb(c2);
			graph[c2].pb(c1);
		}
        if( n == 3)
        {
            cout << "WAKE UP IN, "<< 0 << ", YEARS\n";
            continue;
        }
		int sum = 0;

		while(1)
		{
			t = doit();
			if( t == -1)
			{
				cout << "THIS BRAIN NEVER WAKES UP\n";
				break;
			}
			else if( !t)
			{
                ++sum;
				cout << "WAKE UP IN, "<< sum << ", YEARS\n";
				break;
			}
			else
				++sum;
		}
	}
}
