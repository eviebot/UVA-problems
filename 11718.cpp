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

unordered_map <int, lli> mymap;
unordered_map <int, lli>::iterator iter;
lli test, n, k, mod, t, i;
lli sum, temp;


lli findstuff(lli s){
	iter = mymap.find(s);
	if(iter!= mymap.end())
		return iter->se;

	lli val = (findstuff(s/2)*findstuff(s-s/2))%mod;

	mymap.insert(MP(s, val));
	return val;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	cin >> test;

	for(int z = 1; z <= test; ++z){
		cin >> n >> k >> mod;

		mymap.clear();
		sum = 0;
		for(i = 1; i <= n; ++i){
			cin >> temp;
			sum += temp;
		}
		sum %= mod;

		mymap[0] = 1;
		mymap[1] = n;
		lli multi = (k * findstuff(k-1))%mod;

		cout << "Case "<< z << ": "<< (sum*multi)%mod << "\n";
	}
}