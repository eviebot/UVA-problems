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

	lli t, n, z, p, q, g;
	cin >> t;

	for(z = 1; z <= t; ++z){
		cin >> n;
		cout << "Case "<< z << ": ";
		if( n == 1){
			cout << 0 << "\n";
			continue;
		}
		
		p = n * (n-1);
		q = 4;

		g = __gcd(p, q);
		p /= g;
		q /= g;

		if(q == 1){
			cout << p << "\n";
		}
		else{
			cout << p << "/"<< q << "\n";
		}
	}
}