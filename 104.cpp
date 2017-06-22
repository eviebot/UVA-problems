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
double drooler;
double matrix[21][21];
double DP[22][22], backtracker[21][21];
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    int i, j, index, k;
    while(infile >> n)
    {
    	for(i = 1; i <=n; ++i)
    	{
    		for(j = 1; j <= n; ++j)
    		{
    			if( j == i)
    				matrix[i][j] = 0;
    			else
    				infile >> matrix[i][j];
    		}
    	}

    	for(i = 1; i <= n; ++i)
    	{
    		backtracker[i][0] = 0;
    		DP[i][0] = 1000000;
    	}
    	DP[1][0] = 0;
    	backtracker[1][0] = 0;

    	for(j = 1; j <= n; ++j)
    	{
    		for(i = 1; i <= n; ++i)
    		{
    			DP[i][j] = DP[i][j-1];
    			backtracker[i][j]= backtracker[i][j-1];
    			for(k = 1; k <= n; ++k)
    			{
    				if( DP[k][j-1] * matrix[k][i] < DP[i][j] )
    				{
    					DP[i][j] = DP[k][j-1] * matrix[k][i];
    					backtracker[i][j] = k;
    				}
    			}
    		}
    	}
    	bool flag = true;
    	for(i = 1; i <= n; ++i)
    	{
    		if( DP[i][n] != DP[i][n-1])
    		{
    			flag = false;
    			break;
    		}
    	}
    	drooler = 1000000;
    	if( !flag)
    		cout << "no arbitrage sequence exists\n";
    	else
    	{
    		cout << 1 ;
    		for(i = 1; i <= n; ++i)
    		{
    			if( DP[i][n-1] * matrix[i][1] < drooler )
    			{
    				index = i;
    				drooler = DP[i][n-1] * matrix[i][1];
    			}
    		}
    		vector <int> storage;
    		i = n-1;
    		while(backtracker[index][i])
    		{
    			storage.pb(backtracker[index][i]);
    			index = backtracker[index][i];
    			--i;
    		}
    		for(i = storage.size()-1 ; i >= 0; --i)
    		{
    			cout << ' '<< storage[i];
    		}
    		cout << 1 << "\n";
    	}
    }
}