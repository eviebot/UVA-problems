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

int x, y, gcd;
void eeuclid(int a, int b){
	if(a == 0){
		y = 1;
		gcd = b;
		x = 0;
		return ;
	}
	eeuclid(b%a, a);
	int x1 = y - (b/a)*x;
	int y1 = x;
	x = x1;
	y = y1;

}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int test, v, k, a, b;
	fastIO;
	cin >> test;
	for(int z =0 ; z < test; ++z){
		cin >> v>> k;
		if(v%k){
			a = v/k;
			b = a+1;
		}else{
			b = a = v/k;
		}
		eeuclid(a, b);

		x *= (v/gcd);
		y *= (v/gcd);
		cout << x << " "<< y << "\n";
	}
}