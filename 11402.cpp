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

vector <int> lazy;
vector <int> tree;
vector <bool> data;
int l, r;

void buildTree(int node, int start, int end, int dec)
{
	int c1 = node*2, c2 = node*2+1, mid = (start+end)/2, val = (end-start+1);
	
	if( lazy[node] == 1)
	{
		tree[node] =  val;
		if( start != end){
		lazy[c1] = 1;
		lazy[c2] = 1;}
	}
	else if( lazy[node] == 0)
	{
		tree[node] = 0;
		if(start != end){
		lazy[c1] = 0;
		lazy[c2] = 0;}
	}
	else if( lazy[node] == 2)
	{
		tree[node] =  val - tree[node];
		if(start != end){
		if( lazy[c1] == 0)
		{
			lazy[c1] = 1;
		}
		else if( lazy[c1] == 1)
		{
			lazy[c1] = 0;
		}
		else if(lazy[c1] == 2)
		{
			lazy[c1] = -1;
		}
		else
		{
			lazy[c1] = 2;
		}

		if( lazy[c2] == 0)
		{
			lazy[c2] = 1;
		}
		else if( lazy[c2] == 1)
		{
			lazy[c2] = 0;
		}
		else if(lazy[c2] == 2)
		{
			lazy[c2] = -1;
		}
		else
		{
			lazy[c2] = 2;
		}}
	}
	lazy[node] = -1;

	if( r < start || end < l)
		return;

	if( start >= l && end <= r)
	{
		if( dec == 1)
		{
			tree[node] = val;
			if( start != end){
			lazy[c1] = 1;
			lazy[c2] = 1;}
		}
		else if(dec == 0)
		{
			tree[node] = 0;
			if(start != end){
			lazy[c1] = 0;
			lazy[c2] = 0;}
		}
		else if( dec == 2)
		{
			tree[node] = val - tree[node];

			if( start != end)
			{
				if( lazy[c1] == 0)
				{
					lazy[c1] = 1;
				}
				else if( lazy[c1] == 1)
				{
					lazy[c1] = 0;
				}
				else if( lazy[c1] == 2)
				{
					lazy[c1] = -1;
				}
				else
				{
					lazy[c1] = 2;
				}

				if( lazy[c2] == 0)
				{
					lazy[c2] = 1;
				}
				else if( lazy[c2] == 1)
				{
					lazy[c2] = 0;
				}
				else if(lazy[c2] == 2)
				{
					lazy[c2] = -1;
				}
				else
				{
					lazy[c2] = 2;
				}
			}
		}
		return;
	}

	buildTree(c1, start, mid, dec);
	buildTree(c2, mid+1, end, dec);

	tree[node] = tree[c1] + tree[c2];
}
void firstbuild(int node, int start, int end)
{
	if( start == end)
	{
		tree[node] = data[start];
		return;
	}

	int mid = (start + end)/2;

	firstbuild(node*2, start, mid);
	firstbuild(node*2+1, mid+1, end);

	tree[node] = tree[node*2] + tree[node*2+1];
}

int solve(int node, int start, int end)
{
	int c1 = node*2, c2 = node*2+1, mid = (start+end)/2, val = (end-start+1);

	if( lazy[node] == 1)
	{
		tree[node] =  val;
		if( start != end){
		lazy[c1] = 1;
		lazy[c2] = 1;}
	}
	else if( lazy[node] == 0)
	{
		tree[node] = 0;
		if(start != end){
		lazy[c1] = 0;
		lazy[c2] = 0;}
	}
	else if( lazy[node] == 2)
	{
		tree[node] =  val - tree[node];
		if(start != end){
		if( lazy[c1] == 0)
		{
			lazy[c1] = 1;
		}
		else if( lazy[c1] == 1)
		{
			lazy[c1] = 0;
		}
		else if(lazy[c1] == 2)
		{
			lazy[c1] = -1;
		}
		else
		{
			lazy[c1] = 2;
		}

		if( lazy[c2] == 0)
		{
			lazy[c2] = 1;
		}
		else if( lazy[c2] == 1)
		{
			lazy[c2] = 0;
		}
		else if(lazy[c2] == 2)
		{
			lazy[c2] = -1;
		}
		else
		{
			lazy[c2] = 2;
		}}
	}
	lazy[node] = -1;

	if( r < start || end < l){
		return 0;
	}

	if( start >= l && end <= r)
	{
		return tree[node];
	}

	return solve(c1, start, mid) + solve(c2, mid+1, end);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int Test, q, q_no, i, M, counter, j, k, T, ans, qt;
	char dec;
	bool temp[51];
	string s;
	cin >> Test;

	for(i = 0; i <= 2048000; ++i)
	{
		lazy.pb(0);
		tree.pb(0);
		data.pb(0);
	}
	for(int z = 1; z <= Test; ++z)
	{
		cin >> M;
		counter = 0;

		for(i = 0; i < M ; ++i)
		{
			cin >> T >> s;

			for(j = 0; j < s.size(); ++j)
			{
				temp[j] = s[j]-'0';
			}

			for(j = 0; j < T; ++j)
			{
				for(k = 0; k < s.size(); ++k)
				{
					data[++counter] = temp[k];
				}
			}
		}
		for(i= 0; i <= 2*counter; ++i)
		{
			lazy[i] = -1;
		}

		cout << "Case "<< z << ":\n";
		qt = 0;
		firstbuild(1, 1, counter);
		cin >> q;

		for(q_no = 1; q_no <= q; ++q_no)
		{
			cin >> dec >> l >> r;
			++l;++r;

			if(dec == 'F')
			{
				buildTree(1, 1, counter, 1);
			}
			else if(dec == 'E')
			{
				buildTree(1, 1, counter, 0);
			}
			else if( dec == 'I')
			{
				buildTree(1, 1, counter, 2);
			}
			else
			{
				ans = solve(1, 1, counter);
				cout << 'Q'<<++qt << ": "<< ans << "\n";
			}
		}
	}
}