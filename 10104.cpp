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

lli a, b, x, y, gcd;
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
lli mini = 1000000000000000ll, a1, a2;
void checker(lli v1, lli v2, lli m){
	lli val = abs(v1) + abs(v2);
	if(val < mini){
		mini = val;
		a1 = v1;
		a2 = v2;
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	while(cin >> a >> b){
		extended_euclid(a, b);
		if(!a){
			cout << "0 1 "<< b << "\n";
			continue;
		}else if(!b){
			cout << "1 0 "<< a << "\n";
			continue;
		}
		lli r1, r2, x1, y1, t;

		bool flag = false;
		if(y < 0){
			t = y;
			y = x;
			x = t;
			t = b;
			b = a;
			a = t;
			flag = true;
		}
		//cout << x << " "<< y << " "<< gcd << "\n";
		r1 = (-x)/(b/gcd);
		r2 = (y)/(a/gcd);

		x1 = x + (r1-2)*(b/gcd);
		y1 = y - (r1-2)*(a/gcd);

		mini = 1000000000000000ll;
		for(int i = 0; i <= 5; ++i){
			x1 += b/gcd;
			y1 -= a/gcd;
			checker(x1, y1, mini);
		}

		x1 = x + (r2-2)*(b/gcd);
		y1 = y - (r2-2)*(a/gcd);

		for(int i = 0; i <= 5; ++i){
			x1 += b/gcd;
			y1 -= a/gcd;
			checker(x1, y1, mini);
		}
		if(flag)
			cout << a2 << " "<< a1 << " "<< gcd << "\n";
		else
			cout << a1 << " "<< a2 << " "<< gcd << "\n";
	}
}