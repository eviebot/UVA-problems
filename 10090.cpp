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

lli x, y, gcd;
void extended_euclid(lli a, lli b){
	if(!a){
		x = 0;
		y = 1;
		gcd = b;
		return ;
	}
	extended_euclid(b%a, a);

	lli x1 = y - (b/a)*x;
	lli y1 = x;
	x = x1;
	y = y1;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	lli n, n1, n2, c1, c2, t, r1, r2, x1, y1;
	while(cin >> n){
		if(!n)
			break;
		cin >> c1 >> n1 >> c2 >> n2;
		extended_euclid(n1, n2);
		if(n%gcd){
			cout << "failed\n";
			continue;
		}

		x *= (n/gcd);
		y *= (n/gcd);
		
		
		r1 = floor((double)(x)/(n2/gcd));
		r2 = ceil((double)(-y)/(n1/gcd));
		lli i1 = -1, i2, mini = 1000000000000000ll;
		
		x1 = x - (r2*(n2/gcd));y1 = y + (r2*(n1/gcd));

		//cout << x1 << " "<< y1 << " "<< r1 << " "<< r2 << "\n";

		if(x1 >= 0 && y1 >= 0 && x1*c1+y1*c2 < mini){
			mini = x1*c1 + y1*c2;
			i1 = x1;
			i2 = y1;
		}

		x1 = x - (r1*(n2/gcd));y1 = y + (r1*(n1/gcd));

		//cout << x1 << " "<< y1 << " "<< r1 << " "<< r2 << "\n";

		if(x1 >= 0 && y1 >= 0 && x1*c1+y1*c2 < mini){
			mini = x1*c1 + y1*c2;
			i1 = x1;
			i2 = y1;
		}

		r1 = ceil((double)(-x)/(n2/gcd));
		r2 = floor((double)(y)/(n1/gcd));

		x1 = x + (r1*(n2/gcd));y1 = y - (r1*(n1/gcd));
		
		//cout << x1 << " "<< y1 << " "<< r1 << " "<< r2 << "\n";

		if(x1 >= 0 && y1 >= 0 && x1*c1+y1*c2 < mini){
			mini = x1*c1 + y1*c2;
			i1 = x1;
			i2 = y1;
		}

		x1 = x + (r2*(n2/gcd));y1 = y - (r2*(n1/gcd));
		//cout << x1 << " "<< y1 << " "<< r1 << " "<< r2 << "\n";

		if(x1 >= 0 && y1 >= 0 && x1*c1+y1*c2 < mini){
			mini = x1*c1 + y1*c2;
			i1 = x1;
			i2 = y1;
		}

		if(i1 != -1)
			cout << i1 << " "<< i2 << "\n";
		else
			cout << "failed\n";
	}
}