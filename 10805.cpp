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

int n;
bool graph[26][26][2], visited[26];
int dist[26], maxi[26];
int search_1(int src)
{
	queue <int> myq;
	int j , temp, maximum= 0;
	myq.push(src);
	for(j = 0; j < n; ++j)
	{
		visited[j] = 0;
	}

	visited[src] = 1;
	dist[src] = 0;

	while(!myq.empty())
	{
		temp = myq.front();
		myq.pop();

		for(j = 0; j < n; ++j)
		{
			if( graph[temp][j][0] && !visited[j])
			{
				visited[j] = 1;
				myq.push(j);
				dist[j] = dist[temp] + 1;
			}
		}
	}

	for(j = 0; j < n; ++j)
		maximum = max(maximum, dist[j]);
	return maximum;
}

void search_2(int centre)
{
	int j, temp;
	queue <int> myq;
	for(j= 0; j < n; ++j)
		visited[j] = 0;
	visited[centre] = 1;
	myq.push(centre);

	while(!myq.empty())
	{
		temp = myq.front();
		myq.pop();

		for(j = 0; j < n; ++j)
		{
			if( graph[temp][j][0])
			{
				if( !visited[j])
				{
					visited[j] = 1;
					graph[temp][j][1] = 1;
					graph[j][temp][1] = 1;
					myq.push(j);
				}
			}
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int cases, i, u, v, j, m;

	infile >> cases;

	for(int z = 1; z <= cases; ++z)
	{
		vector <pair <int, int>> candi;
		infile >> n >> m;
		for(i = 0; i < 26; ++i)
		{
			for(j = 0; j < 26; ++j)
			{
				graph[i][j][0] = 0;
				graph[i][j][1] = 0;
			}
		}

		for(i = 0; i < m; ++i)
		{
			infile >> u >> v;
			candi.pb(MP(u, v));
			graph[u][v][0] = 1;
			graph[v][u][0] = 1;
		}

		for(i = 0; i < n; ++i)
		{
			maxi[i] = search_1(i);
			//cout << i << " "<< maxi[i] << "\n";
		}

		int minimum = INT_MAX, maximum, mini2 = INT_MAX;
		vector <int> index;

		for(i = 0; i < n; ++i)
		{
			if( maxi[i] < minimum)
			{
				minimum = maxi[i];
				index.clear();
				index.pb(i);
			}
			else if( maxi[i] == minimum)
				index.pb(i);
		}

		for(int ii = 0; ii < index.size(); ++ii)
		{
			maximum = 0;
			for(j = 0; j < candi.size(); ++j)
			{
				graph[candi[j].fi][candi[j].se][0] = 1;
				graph[candi[j].se][candi[j].fi][0] = 1;
				graph[candi[j].fi][candi[j].se][1] = 0;
				graph[candi[j].se][candi[j].fi][1] = 0;
			}
			search_2(index[ii]);

			for(i = 0; i < n; ++i)
			{
				for(j = 0; j < n; ++j)
				{
					graph[i][j][0] = graph[i][j][1];
				}
			}
			for(i = 0; i < n; ++i)
			{
				maxi[i] = search_1(i);
				//cout << i << " "<< maxi[i] << "\n";
				maximum = max(maximum, maxi[i]);
			}
			cout << index[ii] << " "<< maximum <<"\n";
			mini2 = min(mini2, maximum);

		}
		cout << "Case #"<< z << ":\n"<< mini2<< "\n\n";
	}
}