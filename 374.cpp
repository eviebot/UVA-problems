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

lli M;
lli fastexp(lli x, lli y){
	x = x%M;
	lli res = 1;
	while(y){
		if(y&1)
			res = (res*x)%M;
		y = y>>1;
		x = (x*x)%M;
	}
	return res;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	lli B, P;
	while(cin >> B >> P >> M){
		cout << fastexp(B, P) << "\n";
	}
}