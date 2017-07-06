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

int n_apps = 0;
int apps[27][2], graph[40][40], src, sink, matcher[27];
bool visited[40];
int configure[40];

void dfs(int root)
{
	if(visited[root])
		return;
	
	visited[root] = 1;
	if(root > 9 && root < src)
	{
		cout << (char)(apps[root][0]);
		return;
	}
	for(int i = 0; i < sink; ++i)
	{
		if(graph[root][i])
		{
			dfs(i);
		}
	}
	return;
}
bool bfs()
{
	bool flag = true;
	queue <int> myq;
	myq.push(src);
	int i, prev, next;
	for(i = 0; i <= sink; ++i)
	{
		configure[i] = -1;
		visited[i] = 0;
	}
	visited[src] = 1;

	while( !myq.empty() && flag)
	{
		prev = myq.front();
		myq.pop();
		for(i = 0; i <= sink; ++i)
		{
			if( graph[prev][i] && !visited[i])
			{
				myq.push(i);
				visited[i] = 1;
				configure[i] = prev;
				if( i == sink)
				{
					flag = false;
					break;
				}
			}
		}
	}

	next = sink;
	if( configure[sink] == -1)
		return false;
	while( configure[next] != -1)
	{
		prev = configure[next];
		graph[prev][next] --;
		graph[next][prev] ++;
		next = prev;
	}
	return true;
}
void max_flow()
{
	int i, j;
	bool flag = true;
	for(i = 10; i < src; ++i)
	{
		graph[src][i] = apps[i][1];
	}
	for(i = 0; i < 10; ++i)
	{
		graph[i][sink] = 1;
	}

	

	while(bfs());

	/*cout << "  ";
	for(i = 0; i < 40; ++i)
	{
		cout << i%10 << " ";
	}
	cout << "\n";
	for(i = 0; i < 40; ++i)
	{
		cout << i%10 << ' ';
		for(j = 0; j < 40; ++j)
		{
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}*/
	for(i = 10; i < src; ++i)
	{
		//cout << graph[src][i] << " "<< (char)(apps[i][0]) << "\n";
		if( graph[src][i])
		{
			flag = false;
		}
	}
	if( flag)
	{
		for(i = 0; i < 10; ++i)
		{
			for(j = 0; j <= sink; ++j)
			{
				visited[j] = 0;
			}
			if(graph[i][sink])
				cout << '_';
			else
				dfs(i);
		}
		cout << "\n";
	}
	else
		cout << "!\n";

}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	string s;
	char c;
	int i, t, j;
	for(i = 0; i < 40; ++i)
	{
		for(j= 0; j < 40 ; ++j)
		{
			graph[i][j] = 0;
		}
	}
	for(i = 0; i < 27; ++i)
	{
		apps[i][0] = 0;
		apps[i][1] = 0;
		matcher[i] = 0;
	}
	
	while(getline(cin, s))
	{
		if( !s.size())
		{
			src = n_apps + 10;
			sink = src+1;

			max_flow();
			for(i = 0; i < 27; ++i)
			{
				matcher[i] = 0;
				apps[i][1] = 0;
				apps[i][0] = 0;
			}
			n_apps = 0;
			for(i = 0; i < 40; ++i)
			{
				for(j= 0; j < 40 ; ++j)
				{
					graph[i][j] = 0;
				}
			}


			continue;
		}
		bool new_flag = false;
		c = s[0];
		apps[n_apps+10][0] = c;
		c-= 'A';
		if(!matcher[c]){
			matcher[c] = n_apps + 10;
			++n_apps;
		}
		i = 1;
		t = 0;
		while(s[i] != ' ')
		{
			t *= 10;
			t += s[i]-'0';
			++i;
		}
		apps[matcher[c]][1] += t;
		++i;

		while(s[i] != ';')
		{
			graph[matcher[c]][s[i]-'0'] = 1;
			++i;	
		}
		
		
	}
	src = n_apps + 10;
	sink = src+1;
	max_flow();
}