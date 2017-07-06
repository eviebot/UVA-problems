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

int n, m, p, graph[31][31][4], configure[32][32][2], sinklog[32][32];
char data[32][32];
bool visited[32][32];
vector <pair <int, int>> src, sink;
string s;
char c;

int bfs(int r, int c)
{
	queue <pair <int, int>> myq;
	pair <int, int> temp;
	int i, j, R, C, tsinkR, tsinkC, index, prevC, prevR;
	bool flag = false;

	for(i = 0; i <= m+1; ++i)
	{
		visited[0][i] = 1;
		visited[n+1][i] = 1;
	}
	for(i = 0; i <= n+1; ++i)
	{
		visited[i][0] = 1;
		visited[i][m+1] = 1;
	}

	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= m;++j)
		{
			configure[i][j][0] = -1;
			visited[i][j] = 0;
		}
	}
	visited[r][c] = 1;
	myq.push(MP(r, c));

	while(!myq.empty())
	{
		temp = myq.front();
		R = temp.fi;
		C = temp.se;
		myq.pop();
		

		for(i = 0; i < sink.size(); ++i)
		{
			if( R == sink[i].fi && C == sink[i].se)
			{
				if(sinklog[R][C]){
				flag = true;
				sinklog[R][C]--;
				break;}
			}
		}
		if(flag)
			break;
		if( !visited[R-1][C] && graph[R][C][0] )
		{
			visited[R-1][C] = 1;
			myq.push(MP(R-1, C));
			configure[R-1][C][0] = R;
			configure[R-1][C][1] = C;
		}

		if( !visited[R+1][C] && graph[R][C][2] )
		{
			visited[R+1][C] = 1;
			myq.push(MP(R+1, C));
			configure[R+1][C][0] = R;
			configure[R+1][C][1] = C;
		}

		if( !visited[R][C+1] && graph[R][C][1])
		{
			visited[R][C+1] = 1;
			myq.push(MP(R, C+1));
			configure[R][C+1][0] = R;
			configure[R][C+1][1] = C;
		}

		if( !visited[R][C-1] && graph[R][C][3])
		{
			visited[R][C-1] = 1;
			myq.push(MP(R, C-1));
			configure[R][C-1][0] = R;
			configure[R][C-1][1] = C;
		}
	}
	if( !flag)
		return 0;

	tsinkC = C;
	tsinkR = R;

	while(configure[tsinkR][tsinkC][0] != -1)
	{
		prevR = configure[tsinkR][tsinkC][0];
		prevC = configure[tsinkR][tsinkC][1];

		if( tsinkR == prevR+1)
		{
			index = 2;
		}
		else if(tsinkR == prevR - 1)
		{
			index = 0;
		}
		else if( tsinkC == prevC + 1)
		{
			index = 1;
		}
		else
		{
			index = 3;
		}

		graph[prevR][prevC][index] -= 1;
		tsinkR = prevR;
		tsinkC = prevC;
	}
	/*for(i = 1; i <= n; ++i)
	{
		for(j = 1;  j<= m; ++j)
		{
			cout <<i << " "<< j << " "<< graph[i][j][0] << " "<< graph[i][j][1] << " "<< graph[i][j][2] << " "<< graph[i][j][3]<<'\n';
		}
		cout << "\n";
	}*/
	return 1;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");


	int i, j, n_max, n_ppl;
	while(infile >> n >> m >> p)
	{
		src.clear();
		sink.clear();
		
		for(i = 1; i <= n; ++i)
		{
			for(j = 1; j <= m; ++j)
			{
				sinklog[i][j] = 0;

			}
		}
		for(i = 1; i <= n; ++i)
		{
			infile >> s;
			for(j = 1; j <= m; ++j)
			{
				c = s[j-1];
				data[i][j] = c;
				if( c == '~' )
				{
					graph[i][j][0] = 0;
					graph[i][j][1] = 0;
					graph[i][j][2] = 0;
					graph[i][j][3] = 0;
				}
				else if( c == '@')
				{
					graph[i][j][0] = 1e9;
					graph[i][j][1] = 1e9;
					graph[i][j][2] = 1e9;
					graph[i][j][3] = 1e9;
				}
				else if( c == '.')
				{
					graph[i][j][0] = 1;
					graph[i][j][1] = 1;
					graph[i][j][2] = 1;
					graph[i][j][3] = 1;
				}
				else if( c == '*')
				{
					graph[i][j][0] = 1;
					graph[i][j][1] = 1;
					graph[i][j][2] = 1;
					graph[i][j][3] = 1;
					src.pb(MP(i, j));
				}
				else
				{
					sinklog[i][j] = p;
					sink.pb(MP(i, j));
				}
			}
		}
		for(i= 1; i <= n ;++i)
		{
			for(j = 1; j <= m; ++j)
			{
				if(sinklog[i][j])
				{
					if( data[i-1][j] == '#')
					{
						graph[i][j][0] = 1e9;
					}
					else
					{
						if(data[i-1][j] == '.' || data[i-1][j] == '*')
							graph[i][j][0] = 1;
						else if(data[i-1][j] == '~')
							graph[i][j][0] = 0;
						else
							graph[i][j][0] = 1e9;
					}

					if( data[i][j+1] == '#')
					{
						graph[i][j][1] = 1e9;
					}
					else
					{
						if(data[i][j+1] == '.' || data[i][j+1] == '*')
							graph[i][j][1] = 1;
						else if(data[i][j+1] == '~')
							graph[i][j][1] = 0;
						else
							graph[i][j][1] = 1e9;
					}

					if( data[i+1][j] == '#')
					{
						graph[i][j][2] = 1e9;
					}
					else
					{
						if(data[i+1][j] == '.' || data[i+1][j] == '*')
							graph[i][j][2] = 1;
						else if(data[i+1][j] == '~')
							graph[i][j][2] = 0;
						else
							graph[i][j][2] = 1e9;
					}

					if( data[i][j-1] == '#')
					{
						graph[i][j][3] = 1e9;
					}
					else
					{
						if(data[i][j-1] == '.' || data[i][j-1] == '*')
							graph[i][j][3] = 1;
						else if(data[i][j-1] == '~')
							graph[i][j][3] = 0;
						else
							graph[i][j][3] = 1e9;
					}
				}
			}
		}
		
		int sum = 0;
		for(i = 0; i < src.size(); ++i)
		{
			
			//cout << src[i].fi << " "<< src[i].se << "\n";
			sum += bfs(src[i].fi, src[i].se);
			for(j = 0; j < sink.size(); ++j)
			{ 
			//	cout << sink[j].fi << ' ' << sink[j].se << " "<< sinklog[sink[j].fi][sink[j].se]<<"\n";
			}
			
		}
		
		cout << sum << "\n";

	}
}