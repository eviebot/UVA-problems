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

int n, t, k;
vector <vector <int>> graph;
vector <int> temp;
bool visited[5002];
int dist[5002];
vector <int> finalised;
vector <int> finworst, finbest;

void BFS(int src)
{
	int j, temp, maxi = 0;
	for(j = 0; j <= n; ++j)
		visited[j] = 0;
	visited[src] = 1;
	queue <int> myq;

	dist[src] = 0;
	myq.push(src);

	while(!myq.empty())
	{
		temp = myq.front();
		myq.pop();

		for(j = 0; j < graph[temp].size(); ++j)
		{
			if( !visited[graph[temp][j]])
			{
				visited[graph[temp][j]] = 1;
				myq.push(graph[temp][j]);
				dist[graph[temp][j]] = dist[temp] + 1;
			}
		}
	}

	for(j = 1; j <= n; ++j)
	{
		maxi = max(maxi, dist[j]);
	}

	for(j = 1; j <= n; ++j)
	{
		if( dist[j] == maxi)
		{
			finworst.pb(j);
		}
	}
}

bool doit()
{
	int i, sum;
	bool flag = false;
	
	for(int j = 1; j <= n; ++j)
	{
		if( !visited[j])
		{
			if( !flag)
				finalised.clear();
			flag = true;
			sum = 0;
			for(i = 0; i < graph[j].size(); ++i)
			{
				if( !visited[graph[j][i]] )
					++sum;
			}
			
			if( sum <= 1)
			{
				finalised.pb(j);
			}
		}
	}
	for(i = 0; i < finalised.size(); ++i)
	{
		visited[finalised[i]] = 1;
	}
	return flag;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, j, maximum, minimum;
	
	while(cin >> n)
	{
		maximum= 0;
		minimum = INT_MAX;
		graph.clear();
		for(i = 0; i <= n; ++i)
		{
			graph.pb(temp);
			visited[i] = 0;
		}

		for(i = 1; i <= n; ++i)
		{
			cin >> k;
			for(j = 0; j < k ; ++j)
			{
				cin >> t;
				graph[i].pb(t);
			}
		}

		while(doit());

		finbest = finalised;
		finworst.clear();

		sort(finbest.begin(), finbest.end());

		
		for(i = 0; i < finbest.size(); ++i)
		{
			BFS(finbest[i]);
		}
		sort(finworst.begin(), finworst.end());

		cout << "Best Roots  :";
		for(i = 0; i < finbest.size(); ++i)
		{
			cout << ' '<< finbest[i] ;
		}
		cout << "\nWorst Roots :";
		for(i = 0; i < finworst.size(); ++i)
		{
			cout << ' '<< finworst[i] ;
		}
		cout<< "\n";
	}
}