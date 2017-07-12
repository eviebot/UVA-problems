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

vector <pair <int, int>> arr;
int findleader(int root)
{
	if( arr[root].fi == root)
		return root;

	return arr[root].fi = findleader(arr[root].fi);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int T, F, i ;
	string s1, s2;
	int l1, l2, num;


	for(i = 0; i <= 200000; ++i)
		arr.pb(MP(i, 0));

	cin >> T;
	for(int z = 0; z < T; ++z)
	{
		num = 0;
		cin >> F;
		unordered_map <string, int> mymap;
		for(i = 0; i <= 200000; ++i)
		{
			arr[i] = {i, 1};
		}

		for(i = 0; i < F; ++i)
		{
			cin >> s1 >> s2;
			if( mymap.find(s1) == mymap.end())
			{
				mymap[s1] = ++num;
			}
			if( mymap.find(s2) == mymap.end())
			{
				mymap[s2] = ++num;
			}
			l1 = findleader(mymap[s1]);
			l2 = findleader(mymap[s2]);

			if(l1 == l2){
				cout << arr[l1].se << "\n";
			}
			else
			{
				cout << arr[l1].se+arr[l2].se<< "\n";

                if( arr[l1].se > arr[l2].se)
                {
                    arr[l2].fi = l1;
                    arr[l1].se += arr[l2].se;
                }
                else
                {
                    arr[l1].fi = l2;
                    arr[l2].se += arr[l1].se;
                }
			}
		}
	}
}
