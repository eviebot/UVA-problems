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

	fastIO;
	int r, c, i, j, t, x, y;

	while(cin >> r >> c)
	{
		vector <vector <pair <int, int>>> graph;
		vector <pair <int, int>> temp;
		int temparr[c][2];
		for(i = 0; i <= c ;++i)
		{
			graph.pb(temp);
		}
		for(i = 1; i <= r; ++i)
		{
			cin >> t;
			for(j = 0; j < t; ++j)
			{
				cin >> x;
				temparr[j][0] = x;
			}
			for(j = 0; j < t; ++j)
			{
				cin >> x;
				graph[temparr[j][0]].pb(MP(i, x));
			}
		}

		cout << c << " "<< r << "\n";
		for(j = 1; j <= c; ++j)
		{
			cout << graph[j].size();
			if(graph[j].size())
			{
				for(i = 0; i < graph[j].size(); ++i)
				{
					cout << " "<<graph[j][i].fi;
				}
				cout << "\n";
				for(i = 0; i < graph[j].size()-1; ++i)
				{
					cout << graph[j][i].se << " ";
				}

				cout << graph[j][graph[j].size()-1].se ;
			}
			else
			{
				cout << "\n";
			}
			cout << "\n";
		}

	}
}