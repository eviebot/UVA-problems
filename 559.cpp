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

int n_nodes, matcher[26], n_acorns, n_trees;
bool visited[26], checker[26], discard[26];
vector <vector <int>> graph;
vector <int> temp;

void BFS(int src)
{
	visited[src] = 1;
	queue <int> myq;
	int t, j;
	myq.push(src);
	while(!myq.empty())
	{
		t = myq.front();
		myq.pop();
		for(j = 0; j < graph[t].size(); ++j)
		{
			if( !visited[graph[t][j]])
			{
				visited[graph[t][j]] = 1;
				myq.push(graph[t][j]);
			}
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	string s;
	int T, i, n[2], nx;
	char c;
	getline(cin, s);
	istringstream is(s);
	is >> T;
	for(int z = 0; z < T; ++z)
	{
		graph.clear();
		graph.pb(temp);
		n_nodes = 0;
		n_acorns =0;
		n_trees = 0;
		for(i = 0; i < 26; ++i)
		{
			matcher[i] = 0;
			visited[i] = 0;
			discard[i] = 0;
			checker[i] = 0;
		}
		while(getline(cin, s))
		{
			if( s[0] == '*')
				break;
			int x =0;
			for(i = 0; i < s.size(); ++i)
			{
				c = s[i];
				if( c >= 65 && c <= 90)
				{
					n[x++] = c-'A';
				}
			}
			

			if( !matcher[n[0]])
			{
				matcher[n[0]] = ++n_nodes;
				graph.pb(temp);
			}
			if( !matcher[n[1]])
			{
				matcher[n[1]] = ++n_nodes;
				graph.pb(temp);
			}
			graph[matcher[n[0]]].pb(matcher[n[1]]);
			graph[matcher[n[1]]].pb(matcher[n[0]]);

		}
		getline(cin , s);
		for(i = 0; i < s.size(); ++i)
		{
			c = s[i];
			if( c >= 65 && c <= 90)
			{
				nx = c-'A';
				if( !matcher[nx])
				{
					++n_acorns;
				}
				else
				{
					checker[nx] = 1;
				}
			}
		}
		for(i = 0; i < 26; ++i)
		{
			if( matcher[i] && !checker[i])
			{
				discard[matcher[i]] = 1;
				cout << i << "\n";
			}
		}
		for(i = 1; i <= n_nodes; ++i)
		{
			if( !visited[i] && !discard[i])
			{
				++n_trees;
				BFS(i);
			}
		}
		cout << "There are "<< n_trees << " tree(s) and "<< n_acorns << " acorn(s).\n";
	}
}