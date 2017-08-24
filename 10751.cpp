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

	fastIO;
	int t, n;
	cin >> t;
	cout << fixed << setprecision(3);
	for(int z = 1; z <= t; ++z){
		cin >> n;
		double d;
		if(n == 1){
			d = 0;
		}
		else{
			d = n*n+(sqrt(2)-1.0)*(n-2);
		}
		cout << d << "\n\n";
	}
}