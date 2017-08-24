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

bool checker(lli x, lli y, lli a, lli b){
	if(x >= 0 && y > 0 && (y-x == a) && (y+x+1) == b)
		return true;
	return false;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli n, i, x, y;
	fastIO;

	while(cin >> n){
		bool flag = true;
		if(n == -1)
			break;
		vector <pair <lli, lli>> factors;
		n *= 2;
		lli upper = sqrt(n)+1;

		for(i = 1; i <= upper; ++i){
			if( !(n%i)){
				factors.pb(MP(n/i, i));
				factors.pb(MP(i, n/i));
			}
		}
		sort(factors.begin(), factors.end());

		for(i = factors.size()-1; i >= 0; --i){
			//cout << factors[i].fi << " "<< factors[i].se << "\n";
			y = (factors[i].fi+factors[i].se-1)/2;
			x = y - factors[i].fi;
			
			if(checker(x, y, factors[i].fi, factors[i].se)){
				cout << n/2<<" = "<<x+1<<" + ... + "<< y << "\n";
				break;
			}
		}
	}
}