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

int L, U, R;
vector <int> arr;
bool visited[10000], flag;
int dist[10000];
void BFS()
{
	queue <int> myq;
	int j, temp, temp1;
	myq.push(L);
	visited[L] = 1;
	flag = true;
	while(!myq.empty()&& flag)
	{
		temp = myq.front();
		myq.pop();
		for(j = 0; j < R; ++j)
		{
			temp1 = temp + arr[j];
			if( temp1 > 9999)
				temp1 -= (10000);
			if( !visited[temp1])
			{
				visited[temp1] = true;
				dist[temp1] = dist[temp] + 1;
				myq.push(temp1);
				if( temp1 == U)
                {
                    cout << dist[U] << "\n";
                    flag = false;
                }
			}
		}
	}
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int i, z = 1, t;
    while(cin >> L >> U >> R)
    {
    	if(!R)
    		break;

    	for(i = 0; i < 10000; ++i){
    		visited[i] = 0;
    		dist[i] = 0;
    	}
   		arr.clear();
    	for(i = 0; i < R; ++i)
    	{
    		cin >> t;
    		arr.pb(t);
    	}
        cout << "Case "<< z++<<": ";
    	BFS();

    	if( flag)
    		cout << "Permanently Locked\n";
    }
}
