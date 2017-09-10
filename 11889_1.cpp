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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int test, n, i, a, c;
	cin >> test;
	for(int z =0 ; z < test; ++z){
		int b;
		cin >> a >> c;

		if(c%a){
			cout << "NO SOLUTION\n";
			continue;
		}

		int t = __gcd(a, c/a);

		for(int i = 2; i <= sqrt(t); ++i){
			if(!(t%i)){
				while(!(a%i))
					a /= i;
				while(!(t%i))
					t /= i;
			}
		}
		while(t!= 1 && !(a%t))
			a /= t;
		cout << c/a << "\n";
	}
}