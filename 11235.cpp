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
	int n, q, t, prev, i, l, r, up, low, mid, maxi, lf, rf, j;
	while(cin >> n)
	{
		if( !n)
			break;
		cin >> q;
		vector <pair <int, int>> storage;
		prev = INT_MAX;
		l = 0;r = 0;

		for(i = 1; i <= n; ++i)
		{
			cin >> t;
			if( t != prev)
			{
				storage.pb(MP(l , i-1));
				l = i;
				prev = t;
			}
		}
		storage.pb(MP(l, i-1));


		for(i = 0; i < q; ++i)
		{
			cin >> l >> r;
			maxi = 0;
			up = storage.size()-1;
			low = 1;

			while( low <= up )
			{
				mid = (up+low)/2;
				if( storage[mid].fi <= l && l <= storage[mid].se )
				{
					break;
				}
				else if( storage[mid].fi > l)
				{
					up = mid-1;
				}
				else
				{
					low = mid+1;
				}
			}

			lf = mid;

			up = storage.size()-1;
			low = 1;

			while( low <= up )
			{
				mid = (up+low)/2;
				if( storage[mid].fi <= r && r <= storage[mid].se )
				{
					break;
				}
				else if( storage[mid].fi > r)
				{
					up = mid-1;
				}
				else
				{
					low = mid+1;
				}
			}

			rf = mid;
			if( lf != rf)
				maxi = max( storage[lf].se - l + 1, r- storage[rf].fi + 1 );
			else
				maxi = r-l+1;
			for(j = lf+1; j < rf; ++j)
			{
				maxi = max( maxi, storage[j].se-storage[j].fi+1);
			}

			cout << maxi << "\n";
		}
	}
}