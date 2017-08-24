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

vector <int> data, tree;
int l, r;

void firstbuild(int node, int start, int end)
{
	if( start == end)
	{
		tree[node] = data[start];
		return;
	}
	int mid = (start+end)/2;

	firstbuild(node*2, start, mid);
	firstbuild(node*2+1, mid+1, end);
	tree[node] = tree[node*2] * tree[node*2+1];
}

void change(int node, int start, int end)
{
	int mid = (start+end)/2;

	if( start == end)
	{
		tree[node] = r;
		return;
	}

	if( start <= l && l <= mid)
		change(node*2, start, mid);
	else
		change(node*2+1, mid+1, end);

	tree[node] = tree[node*2] * tree[node*2+1];
}

int solve(int node, int start, int end)
{
	if( r < start || end < l )
		return 1;

	int mid = (start+end)/2;

	if( start >= l && end <= r)
		return tree[node];

	return solve(node*2, start, mid) * solve(node*2+1, mid+1, end);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, k, i, t, ans;
	char dec;
	
	for(i = 0; i <= 200002; ++i)
	{
		data.pb(0);
		tree.pb(0);
	}

	while(cin >> n >> k)
	{
		for(i = 1; i <= n; ++i)
		{
			cin >> t;
			if( t > 0)
				data[i] = 1;
			else if( t < 0)
				data[i] = -1;
			else
				data[i] = 0;
		}

		firstbuild(1, 1, n);

		for(i =0 ; i < k ; ++i)
		{
			cin >> dec >> l >> r;
			if( dec == 'C')
			{
				if( r > 0)
					r = 1;
				else if( r < 0)
					r = -1;
				else
					r = 0;
				change(1, 1, n);
			}
			else
			{
				ans = solve(1, 1, n);
				if( ans > 0)
					cout << '+';
				else if( ans < 0)
					cout << '-';
				else
					cout << '0';
			}
		}
		cout << "\n";
	}
}