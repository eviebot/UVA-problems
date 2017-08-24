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

vector <pair <int, int>> myvec;

int findleader(int root)
{
    if( myvec[root].fi == root)
        return root;

    return myvec[root].fi = findleader(myvec[root].fi);
}

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int T, i, n, succ, unsucc;
	char c, ct;
	int c1, c2, l1, l2;
	cin >> T;
	for(int z = 0; z < T; ++z)
	{
	    succ = 0;
	    unsucc = 0;
	    cin >> n;
		myvec.clear();
		for(i = 0; i <= n; ++i)
		{
			myvec.pb(MP(i, 0));
		}

        while(true)
        {
            ct = cin.get();
            if(cin.peek()== '\n')
            {
                cout << succ << ","<< unsucc << "\n\n";
                break;
            }
            if(cin.peek() == EOF)
            {
                cout << succ << ","<< unsucc << "\n";
                break;
            }
            cin >> c >> c1 >> c2;
            l1 = findleader(c1);
			l2 = findleader(c2);

			if( c == 'c' && l1 != l2)
			{
				if( myvec[l1].se > myvec[l2].se )
				{
					myvec[l2].fi = l1;
				}
				else if( myvec[l1].se < myvec[l2].se)
				{
					myvec[l1].fi = l2;
				}
				else
				{
					myvec[l2].fi = l1;
					++myvec[l1].se;
				}
			}
			else if( c== 'q')
			{
				if( l1 == l2)
				{
					++succ;
				}
				else
				{
					++unsucc;
				}
			}
        }
	}
}
