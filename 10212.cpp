#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int fastexp(int x, int y){		// find (x^y)%mod
	int res = 1;
	while(y){
		if(y&1) 
			res = (res*x)%10;
		y = y>>1;
		x = (x*x)%10;
	}
	return res;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	vector <int> sieve;
	int i, n, m, j, t, multi;
	sieve.resize(20000001);
	for(i = 1; i <= 20000000; ++i)
		sieve[i] = 0;

	
	sieve[1] = 1;
	for(i = 2; i <= 20000000; ++i){
		if(!sieve[i]){
			j = i;
			while(j <= 20000000){
				sieve[j] = i;
				j += i;
			}
		}
	}
	while(cin >> n >> m){
		unordered_map <int, int> factors;
		for(i = n-m+1; i <= n; ++i){
			j = i;
			while(j != 1){
				factors[sieve[j]]++;
				j /= sieve[j];
			}
		}
		multi = 1;
		if(factors[2] > factors[5]){
			multi = fastexp(2, factors[2]-factors[5]);
		}else{
			multi = fastexp(5, factors[5]-factors[2]);
		}
		for(auto it:factors){
			if(it.fi != 2 && it.fi != 5){
				multi = (multi*fastexp(it.fi, it.se))%10;
			}
		}
		cout << multi << "\n";
	}
}